# Script to commit each day with proper dates (1 day gap)
# Day 1 = 99 days ago, Day 2 = 98 days ago, ..., Day 100 = today

$baseDate = Get-Date
$daysAgo = 99

# Commit each Day folder separately
for ($day = 1; $day -le 100; $day++) {
    $commitDate = $baseDate.AddDays(-$daysAgo)
    $dateString = $commitDate.ToString("yyyy-MM-dd HH:mm:ss")
    
    Write-Host "Committing Day$day with date: $dateString"
    
    # Check if Day folder exists, otherwise check for files
    if (Test-Path "Day$day/") {
        git add "Day$day/"
    } elseif ($day -le 13) {
        # For days 1-13, add individual files
        git add "day${day}*.c" -ErrorAction SilentlyContinue
    } elseif ($day -ge 41 -and $day -le 60) {
        # For days 41-60 in "above 30 question" folder
        git add "above 30 question/day$day.c" -ErrorAction SilentlyContinue
    }
    
    # Commit with custom date (only if there are changes)
    $env:GIT_AUTHOR_DATE = $dateString
    $env:GIT_COMMITTER_DATE = $dateString
    git commit -m "feat: Complete Day $day of 100 Days DSA Challenge" --date="$dateString" --allow-empty-message --allow-empty 2>$null
    
    $daysAgo--
}

# Commit documentation files with today's date
Write-Host "Committing documentation files..."
git add *.md
$todayString = $baseDate.ToString("yyyy-MM-dd HH:mm:ss")
$env:GIT_AUTHOR_DATE = $todayString
$env:GIT_COMMITTER_DATE = $todayString
git commit -m "docs: Add comprehensive documentation for 100 Days DSA Challenge" --date="$todayString" --allow-empty

Write-Host "`nAll commits done! Now force push to update remote..."
Write-Host "Run: git push -f origin main"
Write-Host "`nNote: This will rewrite git history. Make sure you want to do this!"
