param (
	[Parameter(Mandatory=$false)]
	[string]$Project
)

function Build-Packages
{
	param (
		[Parameter(Mandatory=$false)]
		[string]$Project
	)

	$projects = (
		"ICU4NETExtension")

	# Remove previously built packages.
	Remove-Item *.nupkg

	# Get solution directory.
	$solutionDir = Split-Path $dte.Solution.FileName -Parent
	$currentDir = "$solutionDir\NugetPackages"

	# Get NuGet handle.
	$nuget = "$solutionDir\.nuget\NuGet.exe"

	foreach ($project in $projects | where {$_ -like "*$Project*"})
	{
		Write-Host "`r`nBuilding '$project' package..." -ForegroundColor 'green' -BackgroundColor 'black'

		$projectDir = "$solutionDir\$project"

		# Make sure .nuspec file exists.
		cd $projectDir
		&$nuget spec -Verbosity quiet
		cd $currentDir

		# Build package.
		&$nuget pack "$projectDir\$project.csproj" `
			-OutputDirectory "$currentDir" `
			-Symbols `
			-Properties Configuration=Release
	}
}

Build-Packages -Project $Project