# Script to reset git history and create fresh commits with proper dates
# This will create a clean history with dates going back 99 days

Write-Host "⚠️  WARNING: This will rewrite your entire git history!" -ForegroundColor Yellow
Write-Host "Press Ctrl+C to cancel, or any key to continue..."
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")

# Backup current branch
Write-Host "`n📦 Creating backup branch..." -ForegroundColor Cyan
git branch backup-before-reset

# Get the first commit (root)
$firstCommit = git rev-list --max-parents=0 HEAD

# Reset to first commit
Write-Host "🔄 Resetting to first commit..." -ForegroundColor Cyan
git reset --soft $firstCommit

# Remove all files from staging
git reset HEAD .

# Now create commits with proper dates
$baseDate = Get-Date
$daysAgo = 99

Write-Host "`n📅 Creating commits with proper dates..." -ForegroundColor Cyan

# Commit each Day folder separately
for ($day = 1; $day -le 100; $day++) {
    $commitDate = $baseDate.AddDays(-$daysAgo)
    $dateString = $commitDate.ToString("yyyy-MM-dd HH:mm:ss")
    
    $hasChanges = $false
    
    # Check if Day folder exists
    if (Test-Path "Day$day/") {
        git add "Day$day/"
        $hasChanges = $true
    } 
    # For days 1-13, add individual files
    elseif ($day -le 13) {
        $files = Get-ChildItem -Path . -Filter "day${day}*.c" -ErrorAction SilentlyContinue
        if ($files) {
            git add "day${day}*.c"
            $hasChanges = $true
        }
    } 
    # For days 41-60 in "above 30 question" folder
    elseif ($day -ge 41 -and $day -le 60) {
        if (Test-Path "above 30 question/day$day.c") {
            git add "above 30 question/day$day.c"
            $hasChanges = $true
        }
    }
    
    # Only commit if there are changes
    if ($hasChanges) {
        Write-Host "  ✓ Day $day - $($commitDate.ToString('yyyy-MM-dd'))" -ForegroundColor Green
        
        $env:GIT_AUTHOR_DATE = $dateString
        $env:GIT_COMMITTER_DATE = $dateString
        git commit -m "feat: Complete Day $day of 100 Days DSA Challenge" --date="$dateString" --quiet
    } else {
        Write-Host "  ⊘ Day $day - No files found" -ForegroundColor DarkGray
    }
    
    $daysAgo--
}

# Commit documentation files with today's date
Write-Host "`n📝 Committing documentation files..." -ForegroundColor Cyan
git add *.md
$todayString = $baseDate.ToString("yyyy-MM-dd HH:mm:ss")
$env:GIT_AUTHOR_DATE = $todayString
$env:GIT_COMMITTER_DATE = $todayString
git commit -m "docs: Add comprehensive documentation for 100 Days DSA Challenge" --date="$todayString" --quiet

# Add any remaining files
Write-Host "`n📄 Adding remaining files..." -ForegroundColor Cyan
git add .
if (git diff --staged --quiet) {
    Write-Host "  No additional files to commit" -ForegroundColor DarkGray
} else {
    git commit -m "chore: Add remaining project files" --date="$todayString" --quiet
    Write-Host "  ✓ Committed remaining files" -ForegroundColor Green
}

Write-Host "`n✅ All commits created successfully!" -ForegroundColor Green
Write-Host "`n📊 Commit summary:" -ForegroundColor Cyan
git log --oneline | Select-Object -First 10

Write-Host "`n🚀 Next steps:" -ForegroundColor Yellow
Write-Host "1. Review the commits: git log --oneline"
Write-Host "2. Force push to remote: git push -f origin main"
Write-Host "3. If something went wrong, restore backup: git reset --hard backup-before-reset"
Write-Host "`n⚠️  Remember: Force push will overwrite remote history!" -ForegroundColor Red
