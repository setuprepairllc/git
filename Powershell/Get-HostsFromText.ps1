
$hosts = Get-Content -Path "path_to_your_file.txt"

function Test-Hosts {
    param (
        [string]$FilePath
    )
    $hosts = Get-Content -Path $FilePath

    ForEach ($host in $hosts) {
        if (Test-Connection -ComputerName $host -Count 1 -Quiet) {
            Write-Host "$host is up" -ForegroundColor Green
        } else {
            Write-Host "$host is down" -ForegroundColor Red
        }
    }
}

