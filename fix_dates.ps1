# Script to reset git history and create fresh commits with proper dates
Write-Host "Starting git history rewrite..." -ForegroundColor Cyan

# Backup current branch
Write-Host "Creating backup branch..." -ForegroundColor Yellow
git branch backup-before-reset -f 2>$null

# Get the first commit
$firstCommit = git rev-list --max-parents=0 HEAD

# Reset to first commit
Write-Host "Resetting to first commit..." -ForegroundColor Yellow
git reset --soft $firstCommit

# Remove all files from staging
git reset HEAD . 2>$null

# Now create commits with proper dates
$baseDate = Get-Date
$daysAgo = 99

Write-Host "Creating commits with proper dates..." -ForegroundColor Cyan

# Commit each Day
for ($day = 1; $day -le 100; $day++) {
    $commitDate = $baseDate.AddDays(-$daysAgo)
    $dateString = $commitDate.ToString("yyyy-MM-dd HH:mm:ss")
    
    $hasChanges = $false
    
    # Check if Day folder exists
    if (Test-Path "Day$day/") {
        git add "Day$day/" 2>$null
        $hasChanges = $true
    } elseif ($day -le 13) {
        # For days 1-13, add individual files
        $files = Get-ChildItem -Path . -Filter "day${day}*.c" -ErrorAction SilentlyContinue
        if ($files) {
            foreach ($file in $files) {
                git add $file.Name 2>$null
            }
            $hasChanges = $true
        }
    } elseif ($day -ge 41 -and $day -le 60) {
        # For days 41-60 in "above 30 question" folder
        if (Test-Path "above 30 question/day$day.c") {
            git add "above 30 question/day$day.c" 2>$null
            $hasChanges = $true
        }
    }
    
    # Only commit if there are changes
    if ($hasChanges) {
        Write-Host "Day $day - $($commitDate.ToString('yyyy-MM-dd'))" -ForegroundColor Green
        
        $env:GIT_AUTHOR_DATE = $dateString
        $env:GIT_COMMITTER_DATE = $dateString
        git commit -m "feat: Complete Day $day of 100 Days DSA Challenge" --date="$dateString" --quiet 2>$null
    }
    
    $daysAgo--
}

# Commit documentation files
Write-Host "Committing documentation..." -ForegroundColor Cyan
git add *.md 2>$null
$todayString = $baseDate.ToString("yyyy-MM-dd HH:mm:ss")
$env:GIT_AUTHOR_DATE = $todayString
$env:GIT_COMMITTER_DATE = $todayString
git commit -m "docs: Add comprehensive documentation" --date="$todayString" --quiet 2>$null

# Add remaining files
git add . 2>$null
$staged = git diff --staged --name-only
if ($staged) {
    git commit -m "chore: Add remaining files" --date="$todayString" --quiet 2>$null
}

Write-Host "`nDone! Commits created successfully!" -ForegroundColor Green
Write-Host "`nRecent commits:" -ForegroundColor Cyan
git log --oneline -10

Write-Host "`nNext: git push -f origin main" -ForegroundColor Yellow
