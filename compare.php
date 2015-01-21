<?php
	//$cod2 = parse_names(file_get_contents("imports_cod2.txt"));
	//$cod4 = parse_names(file_get_contents("imports_cod4.txt"));
	//$a_no_b = array_diff($cod2, $cod4);
	//print_r($a_no_b);
	//$a_no_b = array_diff($cod4, $cod2);
	//print_r($a_no_b);
	
	include("plt_offsets.php");

	$imports = parse_names(file_get_contents($argv[1]));
	sort($imports);

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
	
	$cod4values = parse_value(file_get_contents("compare_cod4_hooks.txt"));
	
	//print_r($cod4values);
	
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

	$libs = array();
	foreach ($imports as $import) {
		$lib = symbol_to_lib($import);
		//echo "########## import=$import $lib ##########\n";
		if ($lib) {
			$libname = $lib;
			$lib = str_replace("libstdc++-6.dll"    , "handle_libstdcpp6", $lib);
			$lib = str_replace("libwinpthread-1.dll", "handle_pthreads"  , $lib);
			$libs[$libname]["list"][] = array("call"=>"Sys_CoD4LinkObject(LD_$import, GetProcAddress($lib, \"$import\"));", "import"=>$import, "func"=>"");
			$libs[$libname]["varname_lib"] = $lib;
		} else {
			if (isset($cod4values[$import])) {
				$func = $cod4values[$import];
				$libs["nolib"]["list"][] = array("call"=>"Sys_CoD4LinkObject(LD_$import, $func);", "import"=>$import, "func"=>$func);
			} else {
				$libs["stubs"]["name"][] = "stub_$import";
				$libs["stubs"]["list"][] = array("call"=>"Sys_CoD4LinkObject(LD_$import, stub_$import);", "import"=>$import, "func"=>"");
			}
		}
	}
	
	foreach ($libs["stubs"]["name"] as $name) {
		echo "int $name() {\n";
		echo "	printf(\"$name()\\n\");\n";
		echo "	//__asm__(\"int $3\");\n";
		echo "	return 1;\n";
		echo "}\n";
	}
	
	echo "\n\n";
	echo "\n\n";
	
	echo "int Sys_CoD4Linker() {\n";
	foreach ($libs as $libname=>$linkfuncs) {
		echo "\n";
		echo "\n";
		echo "	// libname=$libname\n";
		if (substr($libname, -4) == ".dll") {
			$varname = $linkfuncs["varname_lib"];
			echo "	HMODULE $varname = LoadLibrary(\"$libname\");\n";
		}
		//echo "// stubname={$linkfuncs["stubname"]}\n";
		echo "\n";
		foreach ($linkfuncs["list"] as $tmp) {
			$call = $tmp["call"];
			$import = $tmp["import"];
			$func = $tmp["func"];
			//echo "printf(\"import=$import func=$func\\n\");\n";
			echo "	$call\n";
		}
	}
	
	echo "}\n";

	
	
	
	//foreach ($imports as $import) {
	//	$name = substr($import, 3);
	//	echo "	printf(\"handle: %.8p addr=%.8p name=$name\\n\", handle, GetProcAddress(handle_pthread, \"$name\"));\n";
	//}