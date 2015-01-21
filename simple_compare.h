int stub___libc_start_main() {
	printf("stub___libc_start_main()\n");
	//__asm__("int $3");
	return 1;
}
int stub_puts() {
	printf("stub_puts()\n");
	//__asm__("int $3");
	return 1;
}




int Sys_CoD4Linker() {


	// libname=stubs

	Sys_CoD4LinkObject(LD___libc_start_main, stub___libc_start_main);
	Sys_CoD4LinkObject(LD_puts, stub_puts);


	// libname=nolib

	Sys_CoD4LinkObject(LD_printf, printf);
}
