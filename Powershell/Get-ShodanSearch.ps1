set-executionpolicy bypass

function Get-ShodanSearch {
    param (
        [string]$Query,
        [string]$ApiKey = "Your_Shodan_API_Key"
    )
    if ($ApiKey -eq "") {
        Write-Output "Please provide a valid Shodan API key."
    } else {
        $EncodedQuery = [System.Web.HttpUtility]::UrlEncode($Query)
        $Response = Invoke-RestMethod -Uri "https://api.shodan.io/shodan/host/search?query=$EncodedQuery&key=$ApiKey"
	Write-Host $Response
        return $Response
    }
}
