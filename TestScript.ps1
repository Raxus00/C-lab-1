Remove-Item .\Test.exe *>$null
Write-Host "Attempting to compile functions.cpp and main.cpp into Test.exe"
g++ .\functions.cpp .\main.cpp -o Test.exe -Wall -Wextra -Wpedantic -pedantic-errors

if ($?)
{
	Write-Host "Compilation succeded"
	Write-Host "Starting tests"

	$parameterGroups = ("-d", 1, 2, 3, 4, 5, 6, 7), ("-i", 1, 2, 3, 4, 5, 6, 7),
	("-d", 0, 0, 0, 1), ("-i", 0, 0, 0, 1), ("-D", 5, 4, 3, 2, 1, 0), ("-I", 5, 4, 3, 2, 1, 0),
	("-d", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10), ("-i", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10),
	("-d", 313, 42, -33, 23, 86, -67, 0, 91, 554, -259), ("-i", 313, 42, -33, 23, 86, -67, 0, 91, 554, -259),
	("-d", -2, 30, -5, 1, 7), ("-i", -2, 30, -5, 1, 7),
	("-D", 5, 0, 8, -4, 12, -6, 0, 2, 1), ("-I", 5, 0, 8, -4, 12, -6, 0, 2, 1),
	("-d", 9999, -3123, 123456, -654321, 0), ("-i", 9999, -3123, 123456, -654321, 0)

	$allTestsSucceeded = $true

	foreach ($parameters in $parameterGroups)
	{
		Write-Host Testing with parameters: $parameters
		$studentOutput = .\Test.exe $parameters
		$originalOutput = python .\assignment1_main.py $parameters

		if ($studentOutput -eq $originalOutput)
		{
			Write-Host Success!
		}
		else
		{
			$allTestsSucceeded = $false
			Write-Host "Failed!"
			Write-Host "student: " $studentOutput
			Write-Host "original: " $originalOutput
		}
	}

	if($allTestsSucceeded -eq $true)
	{
		Write-Host "All tests succeeded!"
	}
	else
	{
		Write-Host "One or more tests failed"
		Write-Host "All tests must succeed for your submission to be assessed!"
	}
}
else
{
	Write-Host "A compile error occured!"
	Write-Host "Cannot run tests until compilation succeeds!"
}