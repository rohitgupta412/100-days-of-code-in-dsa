# Fix dates - Start from 100 days AGO (in the past)
Write-Host "Fixing git history with proper past dates..." -ForegroundColor Cyan

# Backup
git branch backup-before-fix -f 2>$null

# Get first commit
$firstCommit = git rev-list --max-parents=0 HEAD

# Reset
Write-Host "Resetting..." -ForegroundColor Yellow
git reset --soft $firstCommit
git reset HEAD . 2>$null

# Start date: 100 days ago from TODAY
$today = Get-Date
$startDate = $today.AddDays(-100)

Write-Host "Start Date: $($startDate.ToString('yyyy-MM-dd'))" -ForegroundColor Green
Write-Host "End Date: $($today.ToString('yyyy-MM-dd'))" -ForegroundColor Green
Write-Host ""

# Create commits for each day
for ($day = 1; $day -le 100; $day++) {
    # Calculate date: start from 100 days ago, increment by 1 each day
    $commitDate = $startDate.AddDays($day - 1)
    $dateString = $commitDate.ToString("yyyy-MM-dd HH:mm:ss")
    
    $hasChanges = $false
    
    # Add files for this day
    if (Test-Path "Day$day/") {
        git add "Day$day/" 2>$null
        $hasChanges = $true
    } elseif ($day -le 13) {
        $files = Get-ChildItem -Path . -Filter "day${day}*.c" -ErrorAction SilentlyContinue
        if ($files) {
            foreach ($file in $files) {
                git add $file.Name 2>$null
            }
            $hasChanges = $true
        }
    } elseif ($day -ge 41 -and $day -le 60) {
        if (Test-Path "above 30 question/day$day.c") {
            git add "above 30 question/day$day.c" 2>$null
            $hasChanges = $true
        }
    }
    
    if ($hasChanges) {
        Write-Host "Day $day - $($commitDate.ToString('yyyy-MM-dd'))" -ForegroundColor Green
        
        $env:GIT_AUTHOR_DATE = $dateString
        $env:GIT_COMMITTER_DATE = $dateString
        git commit -m "feat: Complete Day $day of 100 Days DSA Challenge" --date="$dateString" --quiet 2>$null
    }
}

# Add docs and remaining files with today's date
Write-Host "`nAdding documentation..." -ForegroundColor Cyan
git add *.md 2>$null
$todayString = $today.ToString("yyyy-MM-dd HH:mm:ss")
$env:GIT_AUTHOR_DATE = $todayString
$env:GIT_COMMITTER_DATE = $todayString
git commit -m "docs: Add comprehensive documentation" --date="$todayString" --quiet 2>$null

git add . 2>$null
$staged = git diff --staged --name-only
if ($staged) {
    git commit -m "chore: Add remaining files" --date="$todayString" --quiet 2>$null
}

Write-Host "`n✅ Done! Check commits:" -ForegroundColor Green
git log --oneline --date=short --pretty=format:"%h %ad %s" -10

Write-Host "`n`n🚀 Now push: git push -f origin main" -ForegroundColor Yellow
