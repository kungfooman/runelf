<?php
	/*
		Parse:
			00000000      DF *UND*	0000015c  GLIBC_2.0   qsort
			00000000      DF *UND*	00000021              _ZNSs4_Rep10_M_destroyERKSaIcE
			00000000      DF *UND*	00000069  GLIBC_2.1   sem_trywait
			00000000      DF *UND*	00000021              _ZdaPv
		
		Output:
			// file = imports_simple.txt

			LD_printf,
			LD_puts,
			LD___libc_start_main,
	*/
	function parse_names($content) {
		$lines = explode("\n", $content);
		$names = array();
		foreach ($lines as $line) {
			$parts = preg_split("/ +/", $line);
			//echo "parts:".count($parts)."\n";

			$idx = 4;
			if (count($parts) != 5) {
				$idx = 3; // some lines lack the library name
				//print_r($parts);
			}
			if (count($parts) > 1)
				$names[] = trim($parts[$idx]);
		}
		return $names;
	}
	
	function main() {
		global $argv;
		if ( ! isset($argv[1]))
			die("Missing file argument! Example: php plt_offsets.php imports_simple.txt\n");
		
		$file = $argv[1];
		$names = parse_names(file_get_contents($file));
		
		echo "	// file = $file\n";
		foreach ($names as $name)
			echo "	LD_$name,\n";
	}
		
	if (__FILE__ == realpath($argv[0]))
		main();