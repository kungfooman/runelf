int stub__Unwind_Resume() {
	printf("stub__Unwind_Resume()\n");
	//__asm__("int $3");
	return 1;
}
int stub___cxa_atexit() {
	printf("stub___cxa_atexit()\n");
	//__asm__("int $3");
	return 1;
}
int stub___gxx_personality_v0() {
	printf("stub___gxx_personality_v0()\n");
	//__asm__("int $3");
	return 1;
}
int stub___libc_start_main() {
	printf("stub___libc_start_main()\n");
	//__asm__("int $3");
	return 1;
}
int stub_asctime() {
	printf("stub_asctime()\n");
	//__asm__("int $3");
	return 1;
}
int stub_chmod() {
	printf("stub_chmod()\n");
	//__asm__("int $3");
	return 1;
}
int stub_fcntl() {
	printf("stub_fcntl()\n");
	//__asm__("int $3");
	return 1;
}
int stub_fork() {
	printf("stub_fork()\n");
	//__asm__("int $3");
	return 1;
}
int stub_geteuid() {
	printf("stub_geteuid()\n");
	//__asm__("int $3");
	return 1;
}
int stub_getpwuid() {
	printf("stub_getpwuid()\n");
	//__asm__("int $3");
	return 1;
}
int stub_getuid() {
	printf("stub_getuid()\n");
	//__asm__("int $3");
	return 1;
}
int stub_inet_addr() {
	printf("stub_inet_addr()\n");
	//__asm__("int $3");
	return 1;
}
int stub_ioctl() {
	printf("stub_ioctl()\n");
	//__asm__("int $3");
	return 1;
}
int stub_isatty() {
	printf("stub_isatty()\n");
	//__asm__("int $3");
	return 1;
}
int stub_seteuid() {
	printf("stub_seteuid()\n");
	//__asm__("int $3");
	return 1;
}
int stub_signal() {
	printf("stub_signal()\n");
	//__asm__("int $3");
	return 1;
}
int stub_sleep() {
	printf("stub_sleep()\n");
	//__asm__("int $3");
	return 1;
}
int stub_tcgetattr() {
	printf("stub_tcgetattr()\n");
	//__asm__("int $3");
	return 1;
}
int stub_tcsetattr() {
	printf("stub_tcsetattr()\n");
	//__asm__("int $3");
	return 1;
}




int Sys_CoD4Linker() {


	// libname=stubs

	Sys_CoD4LinkObject(LD__Unwind_Resume, stub__Unwind_Resume);
	Sys_CoD4LinkObject(LD___cxa_atexit, stub___cxa_atexit);
	Sys_CoD4LinkObject(LD___gxx_personality_v0, stub___gxx_personality_v0);
	Sys_CoD4LinkObject(LD___libc_start_main, stub___libc_start_main);
	Sys_CoD4LinkObject(LD_asctime, stub_asctime);
	Sys_CoD4LinkObject(LD_chmod, stub_chmod);
	Sys_CoD4LinkObject(LD_fcntl, stub_fcntl);
	Sys_CoD4LinkObject(LD_fork, stub_fork);
	Sys_CoD4LinkObject(LD_geteuid, stub_geteuid);
	Sys_CoD4LinkObject(LD_getpwuid, stub_getpwuid);
	Sys_CoD4LinkObject(LD_getuid, stub_getuid);
	Sys_CoD4LinkObject(LD_inet_addr, stub_inet_addr);
	Sys_CoD4LinkObject(LD_ioctl, stub_ioctl);
	Sys_CoD4LinkObject(LD_isatty, stub_isatty);
	Sys_CoD4LinkObject(LD_seteuid, stub_seteuid);
	Sys_CoD4LinkObject(LD_signal, stub_signal);
	Sys_CoD4LinkObject(LD_sleep, stub_sleep);
	Sys_CoD4LinkObject(LD_tcgetattr, stub_tcgetattr);
	Sys_CoD4LinkObject(LD_tcsetattr, stub_tcsetattr);


	// libname=libstdc++-6.dll
	HMODULE handle_libstdcpp6 = LoadLibrary("libstdc++-6.dll");

	Sys_CoD4LinkObject(LD__ZNKSs4findEPKcj, GetProcAddress(handle_libstdcpp6, "_ZNKSs4findEPKcj"));
	Sys_CoD4LinkObject(LD__ZNKSs5c_strEv, GetProcAddress(handle_libstdcpp6, "_ZNKSs5c_strEv"));
	Sys_CoD4LinkObject(LD__ZNKSs7compareERKSs, GetProcAddress(handle_libstdcpp6, "_ZNKSs7compareERKSs"));
	Sys_CoD4LinkObject(LD__ZNSaIcEC1Ev, GetProcAddress(handle_libstdcpp6, "_ZNSaIcEC1Ev"));
	Sys_CoD4LinkObject(LD__ZNSaIcED1Ev, GetProcAddress(handle_libstdcpp6, "_ZNSaIcED1Ev"));
	Sys_CoD4LinkObject(LD__ZNSs5eraseEjj, GetProcAddress(handle_libstdcpp6, "_ZNSs5eraseEjj"));
	Sys_CoD4LinkObject(LD__ZNSsC1EPKcRKSaIcE, GetProcAddress(handle_libstdcpp6, "_ZNSsC1EPKcRKSaIcE"));
	Sys_CoD4LinkObject(LD__ZNSsC1ERKSs, GetProcAddress(handle_libstdcpp6, "_ZNSsC1ERKSs"));
	Sys_CoD4LinkObject(LD__ZNSsC1Ev, GetProcAddress(handle_libstdcpp6, "_ZNSsC1Ev"));
	Sys_CoD4LinkObject(LD__ZNSsD1Ev, GetProcAddress(handle_libstdcpp6, "_ZNSsD1Ev"));
	Sys_CoD4LinkObject(LD__ZNSsaSEPKc, GetProcAddress(handle_libstdcpp6, "_ZNSsaSEPKc"));
	Sys_CoD4LinkObject(LD__ZNSsaSERKSs, GetProcAddress(handle_libstdcpp6, "_ZNSsaSERKSs"));
	Sys_CoD4LinkObject(LD__ZNSsixEj, GetProcAddress(handle_libstdcpp6, "_ZNSsixEj"));
	Sys_CoD4LinkObject(LD__ZNSspLEPKc, GetProcAddress(handle_libstdcpp6, "_ZNSspLEPKc"));
	Sys_CoD4LinkObject(LD__ZNSspLEc, GetProcAddress(handle_libstdcpp6, "_ZNSspLEc"));
	Sys_CoD4LinkObject(LD__ZdaPv, GetProcAddress(handle_libstdcpp6, "_ZdaPv"));
	Sys_CoD4LinkObject(LD__ZdlPv, GetProcAddress(handle_libstdcpp6, "_ZdlPv"));
	Sys_CoD4LinkObject(LD__Znaj, GetProcAddress(handle_libstdcpp6, "_Znaj"));
	Sys_CoD4LinkObject(LD___cxa_begin_catch, GetProcAddress(handle_libstdcpp6, "__cxa_begin_catch"));
	Sys_CoD4LinkObject(LD___cxa_end_catch, GetProcAddress(handle_libstdcpp6, "__cxa_end_catch"));
	Sys_CoD4LinkObject(LD___cxa_pure_virtual, GetProcAddress(handle_libstdcpp6, "__cxa_pure_virtual"));
	Sys_CoD4LinkObject(LD___cxa_rethrow, GetProcAddress(handle_libstdcpp6, "__cxa_rethrow"));


	// libname=nolib

	Sys_CoD4LinkObject(LD___errno_location, ___errno_location);
	Sys_CoD4LinkObject(LD___xstat, ___xstat);
	Sys_CoD4LinkObject(LD__exit, _exit);
	Sys_CoD4LinkObject(LD__setjmp, _setjmp);
	Sys_CoD4LinkObject(LD_access, _access);
	Sys_CoD4LinkObject(LD_acos, acos);
	Sys_CoD4LinkObject(LD_asin, asin);
	Sys_CoD4LinkObject(LD_atan, atan);
	Sys_CoD4LinkObject(LD_atan2, atan2);
	Sys_CoD4LinkObject(LD_atof, atof);
	Sys_CoD4LinkObject(LD_atoi, atoi);
	Sys_CoD4LinkObject(LD_bind, bind);
	Sys_CoD4LinkObject(LD_calloc, calloc);
	Sys_CoD4LinkObject(LD_ceil, ceil);
	Sys_CoD4LinkObject(LD_close, close);
	Sys_CoD4LinkObject(LD_closedir, closedir);
	Sys_CoD4LinkObject(LD_cos, cos);
	Sys_CoD4LinkObject(LD_ctime, ctime);
	Sys_CoD4LinkObject(LD_dlclose, dlclose);
	Sys_CoD4LinkObject(LD_dlerror, dlerror);
	Sys_CoD4LinkObject(LD_dlopen, dlopen);
	Sys_CoD4LinkObject(LD_dlsym, dlsym);
	Sys_CoD4LinkObject(LD_execl, execl);
	Sys_CoD4LinkObject(LD_exit, exit);
	Sys_CoD4LinkObject(LD_fclose, fclose);
	Sys_CoD4LinkObject(LD_fflush, fflush);
	Sys_CoD4LinkObject(LD_fileno, _fileno);
	Sys_CoD4LinkObject(LD_floor, floor);
	Sys_CoD4LinkObject(LD_fopen, fopen);
	Sys_CoD4LinkObject(LD_fprintf, fprintf);
	Sys_CoD4LinkObject(LD_fputs, fputs);
	Sys_CoD4LinkObject(LD_fread, fread);
	Sys_CoD4LinkObject(LD_free, free);
	Sys_CoD4LinkObject(LD_fseek, fseek);
	Sys_CoD4LinkObject(LD_ftell, ftell);
	Sys_CoD4LinkObject(LD_fwrite, fwrite);
	Sys_CoD4LinkObject(LD_getcwd, _getcwd);
	Sys_CoD4LinkObject(LD_getenv, getenv);
	Sys_CoD4LinkObject(LD_gethostbyname, gethostbyname);
	Sys_CoD4LinkObject(LD_gethostname, gethostname);
	Sys_CoD4LinkObject(LD_gettimeofday, gettimeofday);
	Sys_CoD4LinkObject(LD_htons, htons);
	Sys_CoD4LinkObject(LD_isalnum, isalnum);
	Sys_CoD4LinkObject(LD_isalpha, isalpha);
	Sys_CoD4LinkObject(LD_isdigit, isdigit);
	Sys_CoD4LinkObject(LD_isspace, isspace);
	Sys_CoD4LinkObject(LD_localtime, localtime);
	Sys_CoD4LinkObject(LD_log, log);
	Sys_CoD4LinkObject(LD_longjmp, longjmp);
	Sys_CoD4LinkObject(LD_malloc, malloc);
	Sys_CoD4LinkObject(LD_memcmp, memcmp);
	Sys_CoD4LinkObject(LD_memcpy, memcpy);
	Sys_CoD4LinkObject(LD_memmove, memmove);
	Sys_CoD4LinkObject(LD_memset, memset);
	Sys_CoD4LinkObject(LD_mkdir, _mkdir);
	Sys_CoD4LinkObject(LD_ntohl, ntohl);
	Sys_CoD4LinkObject(LD_opendir, opendir);
	Sys_CoD4LinkObject(LD_printf, printf);
	Sys_CoD4LinkObject(LD_qsort, qsort);
	Sys_CoD4LinkObject(LD_rand, rand);
	Sys_CoD4LinkObject(LD_read, _read);
	Sys_CoD4LinkObject(LD_readdir, readdir);
	Sys_CoD4LinkObject(LD_realloc, realloc);
	Sys_CoD4LinkObject(LD_recvfrom, recvfrom);
	Sys_CoD4LinkObject(LD_remove, remove);
	Sys_CoD4LinkObject(LD_rename, rename);
	Sys_CoD4LinkObject(LD_rint, rint);
	Sys_CoD4LinkObject(LD_rmdir, _rmdir);
	Sys_CoD4LinkObject(LD_select, select);
	Sys_CoD4LinkObject(LD_sendto, sendto);
	Sys_CoD4LinkObject(LD_setsockopt, setsockopt);
	Sys_CoD4LinkObject(LD_sin, sin);
	Sys_CoD4LinkObject(LD_snprintf, _snprintf);
	Sys_CoD4LinkObject(LD_socket, socket);
	Sys_CoD4LinkObject(LD_sprintf, sprintf);
	Sys_CoD4LinkObject(LD_sqrt, sqrt);
	Sys_CoD4LinkObject(LD_sqrtf, sqrtf);
	Sys_CoD4LinkObject(LD_srand, srand);
	Sys_CoD4LinkObject(LD_sscanf, sscanf);
	Sys_CoD4LinkObject(LD_strcasecmp, Q_stricmp);
	Sys_CoD4LinkObject(LD_strcat, strcat);
	Sys_CoD4LinkObject(LD_strchr, strchr);
	Sys_CoD4LinkObject(LD_strcmp, strcmp);
	Sys_CoD4LinkObject(LD_strcpy, strcpy);
	Sys_CoD4LinkObject(LD_strerror, strerror);
	Sys_CoD4LinkObject(LD_strlen, strlen);
	Sys_CoD4LinkObject(LD_strncasecmp, Q_stricmpn);
	Sys_CoD4LinkObject(LD_strncat, strncat);
	Sys_CoD4LinkObject(LD_strncmp, strncmp);
	Sys_CoD4LinkObject(LD_strncpy, strncpy);
	Sys_CoD4LinkObject(LD_strrchr, strrchr);
	Sys_CoD4LinkObject(LD_strstr, strstr);
	Sys_CoD4LinkObject(LD_system, system);
	Sys_CoD4LinkObject(LD_tan, tan);
	Sys_CoD4LinkObject(LD_time, time);
	Sys_CoD4LinkObject(LD_tolower, tolower);
	Sys_CoD4LinkObject(LD_toupper, toupper);
	Sys_CoD4LinkObject(LD_unlink, _unlink);
	Sys_CoD4LinkObject(LD_usleep, usleep);
	Sys_CoD4LinkObject(LD_vsnprintf, vsnprintf);
	Sys_CoD4LinkObject(LD_vsprintf, vsprintf);
	Sys_CoD4LinkObject(LD_write, _write);


	// libname=libwinpthread-1.dll
	HMODULE handle_pthreads = LoadLibrary("libwinpthread-1.dll");

	Sys_CoD4LinkObject(LD_pthread_mutex_init, GetProcAddress(handle_pthreads, "pthread_mutex_init"));
	Sys_CoD4LinkObject(LD_pthread_mutex_lock, GetProcAddress(handle_pthreads, "pthread_mutex_lock"));
	Sys_CoD4LinkObject(LD_pthread_mutex_unlock, GetProcAddress(handle_pthreads, "pthread_mutex_unlock"));
	Sys_CoD4LinkObject(LD_pthread_mutexattr_destroy, GetProcAddress(handle_pthreads, "pthread_mutexattr_destroy"));
	Sys_CoD4LinkObject(LD_pthread_mutexattr_init, GetProcAddress(handle_pthreads, "pthread_mutexattr_init"));
	Sys_CoD4LinkObject(LD_pthread_mutexattr_settype, GetProcAddress(handle_pthreads, "pthread_mutexattr_settype"));
	Sys_CoD4LinkObject(LD_pthread_self, GetProcAddress(handle_pthreads, "pthread_self"));
}
