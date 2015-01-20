

// libname=stubs

Sys_CoD4LinkObject(LD__Unwind_Resume, stub__Unwind_Resume);
Sys_CoD4LinkObject(LD__ZN9__gnu_cxx18__exchange_and_addEPVii, stub__ZN9__gnu_cxx18__exchange_and_addEPVii);
Sys_CoD4LinkObject(LD__ZNKSs4findEPKcjj, stub__ZNKSs4findEPKcjj);
Sys_CoD4LinkObject(LD__ZNSs12_M_leak_hardEv, stub__ZNSs12_M_leak_hardEv);
Sys_CoD4LinkObject(LD__ZNSs4_Rep10_M_destroyERKSaIcE, stub__ZNSs4_Rep10_M_destroyERKSaIcE);
Sys_CoD4LinkObject(LD__ZNSs6appendEPKcj, stub__ZNSs6appendEPKcj);
Sys_CoD4LinkObject(LD__ZNSs6assignEPKcj, stub__ZNSs6assignEPKcj);
Sys_CoD4LinkObject(LD__ZNSs6assignERKSs, stub__ZNSs6assignERKSs);
Sys_CoD4LinkObject(LD__ZNSs7reserveEj, stub__ZNSs7reserveEj);
Sys_CoD4LinkObject(LD__ZNSs9_M_mutateEjjj, stub__ZNSs9_M_mutateEjjj);
Sys_CoD4LinkObject(LD__ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base, stub__ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base);
Sys_CoD4LinkObject(LD__ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base, stub__ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base);
Sys_CoD4LinkObject(LD__ZSt20__throw_out_of_rangePKc, stub__ZSt20__throw_out_of_rangePKc);
Sys_CoD4LinkObject(LD__ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_, stub__ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_);
Sys_CoD4LinkObject(LD___cxa_allocate_exception, stub___cxa_allocate_exception);
Sys_CoD4LinkObject(LD___cxa_atexit, stub___cxa_atexit);
Sys_CoD4LinkObject(LD___cxa_throw, stub___cxa_throw);
Sys_CoD4LinkObject(LD___gxx_personality_v0, stub___gxx_personality_v0);
Sys_CoD4LinkObject(LD___libc_start_main, stub___libc_start_main);
Sys_CoD4LinkObject(LD___udivdi3, stub___udivdi3);
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
Sys_CoD4LinkObject(LD_pthread_create, stub_pthread_create);
Sys_CoD4LinkObject(LD_sem_getvalue, stub_sem_getvalue);
Sys_CoD4LinkObject(LD_sem_init, stub_sem_init);
Sys_CoD4LinkObject(LD_sem_post, stub_sem_post);
Sys_CoD4LinkObject(LD_sem_timedwait, stub_sem_timedwait);
Sys_CoD4LinkObject(LD_sem_trywait, stub_sem_trywait);
Sys_CoD4LinkObject(LD_sem_wait, stub_sem_wait);
Sys_CoD4LinkObject(LD_seteuid, stub_seteuid);
Sys_CoD4LinkObject(LD_signal, stub_signal);
Sys_CoD4LinkObject(LD_sleep, stub_sleep);
Sys_CoD4LinkObject(LD_sysconf, stub_sysconf);
Sys_CoD4LinkObject(LD_tcgetattr, stub_tcgetattr);
Sys_CoD4LinkObject(LD_tcsetattr, stub_tcsetattr);


// libname=libstdc++-6.dll
HMODULE handle_libstdcpp6 = LoadLibrary("libstdc++-6.dll");

Sys_CoD4LinkObject(LD__ZNSsC1EPKcRKSaIcE, GetProcAddress(handle_libstdcpp6, "_ZNSsC1EPKcRKSaIcE"));
Sys_CoD4LinkObject(LD__ZNSsC1ERKSs, GetProcAddress(handle_libstdcpp6, "_ZNSsC1ERKSs"));
Sys_CoD4LinkObject(LD__ZdaPv, GetProcAddress(handle_libstdcpp6, "_ZdaPv"));
Sys_CoD4LinkObject(LD__ZdlPv, GetProcAddress(handle_libstdcpp6, "_ZdlPv"));
Sys_CoD4LinkObject(LD__Znaj, GetProcAddress(handle_libstdcpp6, "_Znaj"));
Sys_CoD4LinkObject(LD___cxa_begin_catch, GetProcAddress(handle_libstdcpp6, "__cxa_begin_catch"));
Sys_CoD4LinkObject(LD___cxa_end_catch, GetProcAddress(handle_libstdcpp6, "__cxa_end_catch"));
Sys_CoD4LinkObject(LD___cxa_pure_virtual, GetProcAddress(handle_libstdcpp6, "__cxa_pure_virtual"));
Sys_CoD4LinkObject(LD___cxa_rethrow, GetProcAddress(handle_libstdcpp6, "__cxa_rethrow"));


// libname=nolib

Sys_CoD4LinkObject(LD___errno_location, ___errno_location);
Sys_CoD4LinkObject(LD___fxstat, ___fxstat);
Sys_CoD4LinkObject(LD___strtod_internal, __strtod_internal);
Sys_CoD4LinkObject(LD___strtol_internal, __strtol_internal);
Sys_CoD4LinkObject(LD___xstat, ___xstat);
Sys_CoD4LinkObject(LD__exit, _exit);
Sys_CoD4LinkObject(LD__setjmp, _setjmp);
Sys_CoD4LinkObject(LD_access, _access);
Sys_CoD4LinkObject(LD_acos, acos);
Sys_CoD4LinkObject(LD_acosf, acosf);
Sys_CoD4LinkObject(LD_asinf, asinf);
Sys_CoD4LinkObject(LD_atan, atan);
Sys_CoD4LinkObject(LD_atan2, atan2);
Sys_CoD4LinkObject(LD_atan2f, atan2f);
Sys_CoD4LinkObject(LD_atanf, atanf);
Sys_CoD4LinkObject(LD_bind, bind);
Sys_CoD4LinkObject(LD_close, close);
Sys_CoD4LinkObject(LD_closedir, closedir);
Sys_CoD4LinkObject(LD_cos, cos);
Sys_CoD4LinkObject(LD_cosf, cosf);
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
Sys_CoD4LinkObject(LD_fopen, fopen);
Sys_CoD4LinkObject(LD_fprintf, fprintf);
Sys_CoD4LinkObject(LD_fputc, fputc);
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
Sys_CoD4LinkObject(LD_isalnum, isalnum);
Sys_CoD4LinkObject(LD_isalpha, isalpha);
Sys_CoD4LinkObject(LD_isspace, isspace);
Sys_CoD4LinkObject(LD_isupper, isupper);
Sys_CoD4LinkObject(LD_localtime, localtime);
Sys_CoD4LinkObject(LD_log, log);
Sys_CoD4LinkObject(LD_longjmp, longjmp);
Sys_CoD4LinkObject(LD_malloc, malloc);
Sys_CoD4LinkObject(LD_memalign, _memalign);
Sys_CoD4LinkObject(LD_memcpy, memcpy);
Sys_CoD4LinkObject(LD_memmove, memmove);
Sys_CoD4LinkObject(LD_memset, memset);
Sys_CoD4LinkObject(LD_mkdir, _mkdir);
Sys_CoD4LinkObject(LD_opendir, opendir);
Sys_CoD4LinkObject(LD_pow, pow);
Sys_CoD4LinkObject(LD_printf, printf);
Sys_CoD4LinkObject(LD_qsort, qsort);
Sys_CoD4LinkObject(LD_rand, rand);
Sys_CoD4LinkObject(LD_read, _read);
Sys_CoD4LinkObject(LD_readdir, readdir);
Sys_CoD4LinkObject(LD_realloc, realloc);
Sys_CoD4LinkObject(LD_recvfrom, recvfrom);
Sys_CoD4LinkObject(LD_remove, remove);
Sys_CoD4LinkObject(LD_rename, rename);
Sys_CoD4LinkObject(LD_rintf, rintf);
Sys_CoD4LinkObject(LD_rmdir, _rmdir);
Sys_CoD4LinkObject(LD_select, select);
Sys_CoD4LinkObject(LD_sendto, sendto);
Sys_CoD4LinkObject(LD_setsockopt, setsockopt);
Sys_CoD4LinkObject(LD_sin, sin);
Sys_CoD4LinkObject(LD_sinf, sinf);
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
Sys_CoD4LinkObject(LD_strdup, _strdup);
Sys_CoD4LinkObject(LD_strerror, strerror);
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
Sys_CoD4LinkObject(LD_vfprintf, vfprintf);
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




int stub__Unwind_Resume() {
	printf("stub__Unwind_Resume()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZN9__gnu_cxx18__exchange_and_addEPVii() {
	printf("stub__ZN9__gnu_cxx18__exchange_and_addEPVii()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZNKSs4findEPKcjj() {
	printf("stub__ZNKSs4findEPKcjj()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZNSs12_M_leak_hardEv() {
	printf("stub__ZNSs12_M_leak_hardEv()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZNSs4_Rep10_M_destroyERKSaIcE() {
	printf("stub__ZNSs4_Rep10_M_destroyERKSaIcE()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZNSs6appendEPKcj() {
	printf("stub__ZNSs6appendEPKcj()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZNSs6assignEPKcj() {
	printf("stub__ZNSs6assignEPKcj()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZNSs6assignERKSs() {
	printf("stub__ZNSs6assignERKSs()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZNSs7reserveEj() {
	printf("stub__ZNSs7reserveEj()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZNSs9_M_mutateEjjj() {
	printf("stub__ZNSs9_M_mutateEjjj()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base() {
	printf("stub__ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base() {
	printf("stub__ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZSt20__throw_out_of_rangePKc() {
	printf("stub__ZSt20__throw_out_of_rangePKc()\n");
	__asm__("int $3");
	return 1;
}
int stub__ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_() {
	printf("stub__ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_()\n");
	__asm__("int $3");
	return 1;
}
int stub___cxa_allocate_exception() {
	printf("stub___cxa_allocate_exception()\n");
	__asm__("int $3");
	return 1;
}
int stub___cxa_atexit() {
	printf("stub___cxa_atexit()\n");
	__asm__("int $3");
	return 1;
}
int stub___cxa_throw() {
	printf("stub___cxa_throw()\n");
	__asm__("int $3");
	return 1;
}
int stub___gxx_personality_v0() {
	printf("stub___gxx_personality_v0()\n");
	__asm__("int $3");
	return 1;
}
int stub___libc_start_main() {
	printf("stub___libc_start_main()\n");
	__asm__("int $3");
	return 1;
}
int stub___udivdi3() {
	printf("stub___udivdi3()\n");
	__asm__("int $3");
	return 1;
}
int stub_asctime() {
	printf("stub_asctime()\n");
	__asm__("int $3");
	return 1;
}
int stub_chmod() {
	printf("stub_chmod()\n");
	__asm__("int $3");
	return 1;
}
int stub_fcntl() {
	printf("stub_fcntl()\n");
	__asm__("int $3");
	return 1;
}
int stub_fork() {
	printf("stub_fork()\n");
	__asm__("int $3");
	return 1;
}
int stub_geteuid() {
	printf("stub_geteuid()\n");
	__asm__("int $3");
	return 1;
}
int stub_getpwuid() {
	printf("stub_getpwuid()\n");
	__asm__("int $3");
	return 1;
}
int stub_getuid() {
	printf("stub_getuid()\n");
	__asm__("int $3");
	return 1;
}
int stub_inet_addr() {
	printf("stub_inet_addr()\n");
	__asm__("int $3");
	return 1;
}
int stub_ioctl() {
	printf("stub_ioctl()\n");
	__asm__("int $3");
	return 1;
}
int stub_isatty() {
	printf("stub_isatty()\n");
	__asm__("int $3");
	return 1;
}
int stub_pthread_create() {
	printf("stub_pthread_create()\n");
	__asm__("int $3");
	return 1;
}
int stub_sem_getvalue() {
	printf("stub_sem_getvalue()\n");
	__asm__("int $3");
	return 1;
}
int stub_sem_init() {
	printf("stub_sem_init()\n");
	__asm__("int $3");
	return 1;
}
int stub_sem_post() {
	printf("stub_sem_post()\n");
	__asm__("int $3");
	return 1;
}
int stub_sem_timedwait() {
	printf("stub_sem_timedwait()\n");
	__asm__("int $3");
	return 1;
}
int stub_sem_trywait() {
	printf("stub_sem_trywait()\n");
	__asm__("int $3");
	return 1;
}
int stub_sem_wait() {
	printf("stub_sem_wait()\n");
	__asm__("int $3");
	return 1;
}
int stub_seteuid() {
	printf("stub_seteuid()\n");
	__asm__("int $3");
	return 1;
}
int stub_signal() {
	printf("stub_signal()\n");
	__asm__("int $3");
	return 1;
}
int stub_sleep() {
	printf("stub_sleep()\n");
	__asm__("int $3");
	return 1;
}
int stub_sysconf() {
	printf("stub_sysconf()\n");
	__asm__("int $3");
	return 1;
}
int stub_tcgetattr() {
	printf("stub_tcgetattr()\n");
	__asm__("int $3");
	return 1;
}
int stub_tcsetattr() {
	printf("stub_tcsetattr()\n");
	__asm__("int $3");
	return 1;
}
