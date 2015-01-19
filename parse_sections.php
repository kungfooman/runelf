<?php
	function parse($content, $what) {
		preg_match_all("/\\W" . $what . "\\W*(\\w{8})\\W*(\\w{8})\\W*(\\w{8})\\W*(\\w{8})/", $content, $tmp);
		return array($tmp[1][0], $tmp[2][0], $tmp[3][0], $tmp[4][0]);
	}
	
	if ( ! isset($argv[1]))
		die("Missing file argument! Example: php parse_sections.php objdump_simple.txt\n");
	
	$file = $argv[1];
	$content = file_get_contents($file);
	$plt = parse($content, ".plt");
	$txt = parse($content, ".text");
	$rod = parse($content, ".rodata");
	$dat = parse($content, ".data");
	$bss = parse($content, ".bss");
	
	echo "// file = $file\n";
	echo "\n";
	echo "#define BIN_SECT_PLT_START      (void *)0x" . $plt[1] . "\n";
	echo "#define BIN_SECT_PLT_LENGTH             0x" . $plt[0] . "\n";
	echo "#define BIN_SECT_TEXT_START     (void *)0x" . $txt[1] . "\n";
	echo "#define BIN_SECT_TEXT_LENGTH            0x" . $txt[0] . "\n";
	echo "#define BIN_SECT_TEXT_FOFFSET           0x" . $txt[3] . "\n";
	echo "#define BIN_SECT_RODATA_START   (void *)0x" . $rod[1] . "\n";
	echo "#define BIN_SECT_RODATA_LENGTH          0x" . $rod[0] . "\n";
	echo "#define BIN_SECT_RODATA_FOFFSET         0x" . $rod[3] . "\n";
	echo "#define BIN_SECT_DATA_START     (void *)0x" . $dat[1] . "\n";
	echo "#define BIN_SECT_DATA_LENGTH            0x" . $dat[0] . "\n";
	echo "#define BIN_SECT_DATA_FOFFSET           0x" . $dat[3] . "\n";
	echo "#define BIN_SECT_BSS_START      (void *)0x" . $bss[1] . "\n";
	echo "#define BIN_SECT_BSS_LENGTH             0x" . $bss[0] . "\n";
	echo "\n";
	preg_match_all("/start address (.*)/", $content, $tmp);
	echo "#define BIN_START_ADRESS                " . $tmp[1][0] . "\n";