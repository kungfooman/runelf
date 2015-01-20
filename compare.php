<?php

	include("plt_offsets.php");

	$cod2 = parse_names(file_get_contents("imports_cod2.txt"));
	$cod4 = parse_names(file_get_contents("imports_cod4.txt"));
	
	//$a_no_b = array_diff($cod2, $cod4);
	//print_r($a_no_b);
	//$a_no_b = array_diff($cod4, $cod2);
	//print_r($a_no_b);
	
	
	function parse_value($content) {
		$lines = explode("\n", $content);
		$tmp = array();
		foreach ($lines as $line)
			if (strpos($line, "//") === false)
			if (strpos($line, "isdead") === false)
				$tmp[] = $line;
		$content = implode("\n", $tmp);
		
		preg_match_all('/\((.*),(.*)\)/', $content, $lines);
		$lines[1] = array_map("trim", $lines[1]);
		$lines[2] = array_map("trim", $lines[2]);
		
		// LD_printf to printf e.g.
		$lines[1] = array_map(function($ldname) {return substr($ldname, 3);}, $lines[1]);
		
		$tmp = array_combine($lines[1], $lines[2]);
		return $tmp;
	}
	
	$values = parse_value(file_get_contents("compare_cod4_hooks.txt"));
	
	//print_r($values);
	
	$sym2lib = file_get_contents("compare_symbol_to_lib.txt");
	
	function symbol_to_lib($symbol) {
		global $sym2lib;
		preg_match_all("/(.*)\W=\W(.*)/", $sym2lib, $tmp);	
		$tmp[1] = array_map("trim", $tmp[1]);
		$tmp[2] = array_map("trim", $tmp[2]);
		$symbols = array_combine($tmp[2], $tmp[1]);
		//print_r($symbols);
		if (isset($symbols[$symbol]))
			return $symbols[$symbol];
		return false;
	}

	$missing = array();
	foreach ($cod2 as $import) {
		$func = "_isdead_dbg_$import); // >>><<<<<<<<<<<<<<<<<<<<>MISSING<<>>>>>>>>>>>>>>>>>>>>>>><<";
		$missing_ = false;
		if (isset($values[$import]))
			$func = $values[$import];
		else
			$missing_ = true;
		$name = $import;
		$lib = symbol_to_lib($name);
		//echo "########## $import $lib name=$name ##########\n";
		if ($lib) {
			$lib = str_replace("libstdc++-6.dll"    , "handle_libstdcpp6", $lib);
			$lib = str_replace("libwinpthread-1.dll", "handle_pthreads"  , $lib);
			echo "	Sys_CoD4LinkObject($import, GetProcAddress($lib, \"$name\"));\n";
			$missing_ = false;
		} else {
			echo "	Sys_CoD4LinkObject($import, $func);\n";
			
		}
		
		if ($missing_)
			$missing[] = "_isdead_dbg_$import";
	}
	
	
	foreach ($missing as $m) {
		echo "int $m() {\n";
		echo "	Com_Printf(\"Is ded: $m\");\n";
		echo "	return 1;\n";
		echo "}\n";
	}
	
	
	
	//foreach ($cod2 as $import) {
	//	$name = substr($import, 3);
	//	echo "	printf(\"handle: %.8p addr=%.8p name=$name\\n\", handle, GetProcAddress(handle_pthread, \"$name\"));\n";
	//}