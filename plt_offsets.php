<?php
	/*
		Parse:
			00000000      DF *UND*	00000000  GLIBC_2.0   printf
			00000000      DF *UND*	00000000  GLIBC_2.0   puts
			00000000      DF *UND*	00000000  GLIBC_2.0   __libc_start_main
		
		Output:
			// file = imports_simple.txt

			LD_printf,
			LD_puts,
			LD___libc_start_main,
	*/
	function parse($content) {
		$lines = explode("\n", $content);
		$names = array();
		foreach ($lines as $line) {
			$parts = explode(" ", $line);
			if (count($parts) > 1)
				$names[] = trim($parts[12]);
		}
		return $names;
	}
	
	if ( ! isset($argv[1]))
		die("Missing file argument! Example: php plt_offsets.php imports_simple.txt\n");
	
	$file = $argv[1];
	$content = file_get_contents($file);
	$names = parse($content);
	
	echo "	// file = $file\n";
	foreach ($names as $name)
		echo "	LD_$name,\n";