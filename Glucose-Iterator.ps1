$files = Get-ChildItem -Filter "ptn*.cnf" | 
         Where-Object { $_.Name -match "^ptn(\d+)\.cnf$" } | 
         Sort-Object { [int]($_.Name -replace 'ptn','' -replace '.cnf','') }

foreach ($file in $files) {

    if ($file.Name -match "ptn(\d+)\.cnf") {
        $number = $matches[1]
        
        Write-Host -NoNewline "Solving $($file.Name)... "

        $output = & glucose -elim -verb=1 $file.FullName 2>&1
        $timeLine = $output | Where-Object { $_ -match "^c CPU time" }

        if ($timeLine -match ":\s*([\d\.]+)\s*s") {
            $timeTaken = $matches[1]
            
            Write-Host "$timeTaken s" -ForegroundColor Green
        }
        "$number	$timeTaken" | Add-Content results.txt
    }
}
