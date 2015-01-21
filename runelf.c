#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BINARY_SIMPLE 0
#define BINARY_COD2 1
#define BINARY_COD4 2

//#define BINARY BINARY_SIMPLE
#define BINARY BINARY_COD2

int file_get_contents(char *filename, unsigned char **buffer, int *len) {
	FILE *file;
	int file_size;
	int read_size;
	char *content;
	file = fopen(filename, "rb");
	if (file == NULL)
		return 0;
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	rewind(file);
	content = malloc(file_size);
	if (content == NULL) {
		fclose(file);
		return 0;
	}
	read_size = fread(content, 1, file_size, file);
	if (file_size != read_size) {
		free(content);
		fclose(file);
		return 0;
	}
	*buffer = content;
	*len = file_size;	
	fclose(file);
	return 1;
}

int Sys_MemoryProtectWrite(void* startoffset, int len)
{
	DWORD oldProtect;
	if(VirtualProtect((LPVOID)startoffset, len, PAGE_READWRITE, &oldProtect) == 0) {
	        printf("Error: Sys_MemoryProtectWrite, startoffset=%.8p len=%.8p Add=%.8p\n", startoffset, len, startoffset+len);
            return 0;
	}
	return 1;
}

int Sys_MemoryProtectExec(void* startoffset, int len)
{
	DWORD oldProtect;
	if(VirtualProtect((LPVOID)startoffset, len, PAGE_EXECUTE_READ, &oldProtect) == 0)
	{
            printf("Sys_MemoryProtectExec");
            return 0;
	}
	return 1;
}
int Sys_MemoryProtectReadonly(void* startoffset, int len)
{
	DWORD oldProtect;
	if(VirtualProtect((LPVOID)startoffset, len, PAGE_READONLY, &oldProtect) == 0)
	{
	        printf("Sys_MemoryProtectReadonly");
            return 0;
	}
	return 1;
}

DWORD SetJump(DWORD addr, void* destination){

	DWORD jmpwidth;
	DWORD restore;
	byte* baddr = (byte*)addr;

	jmpwidth = (DWORD)( destination - (void*)baddr - 5);
	*baddr = 0xe9;
	baddr++;

	restore = *(DWORD*)baddr;
	*(DWORD*)baddr = jmpwidth;

	return restore;
}
void Sys_CoD4LinkObject(int index, void *fun );

#if BINARY == BINARY_COD2
	#include <ctype.h>
	#include <math.h>
	#include <time.h>
	#include <setjmp.h>

	#include "cod2_sections.h"
	#include "cod2_extra_functions.h"
	typedef enum {
		LD_dummy, /*start at 1*/
		#include "cod2_plt_offsets.h"
	}plt_offset_t;
	#include "cod2_compare.h"
#endif
#if BINARY == BINARY_SIMPLE
	#include "simple_sections.h"
	//#include "simple_extra_functions.h"
	typedef enum {
		LD_dummy, /*start at 1*/
		#include "simple_plt_offsets.h"
	}plt_offset_t;
	#include "simple_compare.h"
#endif

void Sys_CoD4LinkObject(int index, void *fun )
{
    typedef byte plt_entry[16];
    plt_entry *entry = BIN_SECT_PLT_START;
    SetJump((DWORD)&entry[index], fun);
	printf("Sys_CoD4LinkObject: index=%d address=%.8p function=%.8p\n", index, entry + index, fun);
}

/*
void __libc_start_main(int (*main) (int, char * *, char * *), int argc, char * * ubp_av, void (*init) (void), void (*fini) (void), void (*rtld_fini) (void), void (* stack_end)) {
	printf("__libc_start_main main=%.8p argc=%c\n", main, argc);
	main(0, NULL, NULL);
	//exit(0);
}
int __cdecl stub_printf(char *msg, ...) {
	printf("stub:printf\n");
	return 3;
}
int __cdecl stub_puts(char *msg, ...) {
	printf("stub:puts %s\n", msg);
	return 3;
}
void Sys_CoD4Linker() {
	Sys_CoD4LinkObject(LD_printf, printf);
	Sys_CoD4LinkObject(LD_puts, stub_puts);
	//Sys_CoD4LinkObject(LD_puts, puts);
	//Sys_CoD4LinkObject(LD_printf, printf);
	Sys_CoD4LinkObject(LD___libc_start_main, __libc_start_main);
}
*/

int Sys_ProtectMemory() {
	/* The order here is crucial as this sections will overlap */
    if ( ! Sys_MemoryProtectReadonly(BIN_SECT_RODATA_START, BIN_SECT_RODATA_LENGTH))
        return 0;
    if ( ! Sys_MemoryProtectWrite(BIN_SECT_DATA_START, BIN_SECT_DATA_LENGTH) )
        return 0;
    if ( ! Sys_MemoryProtectWrite(BIN_SECT_BSS_START, BIN_SECT_BSS_LENGTH))
        return 0;
	/* 4 bytes is gap between .plt end and .text start */
    if ( ! Sys_MemoryProtectExec(BIN_SECT_PLT_START, BIN_SECT_PLT_LENGTH + BIN_SECT_TEXT_LENGTH + 4))
        return 0;
	return 1;
}

int hook_abc() {
	printf("mah first hook yo!\n");
	return 123;
}

int main() {
	unsigned char *fileimage;
	int size, ret;
	#if BINARY == BINARY_COD2
		ret = file_get_contents("cod2_1_3.elf", &fileimage, &size);
	#endif
	#if BINARY == BINARY_SINGLE
		ret = file_get_contents("simple.elf", &fileimage, &size);
	#endif
	if ( ! ret) {
		printf("Error: Could't open file!\n");
		return 1;
	}
	printf("fileimage=%.8p len=%.8p\n", fileimage, size);

	printf("Copy fileimage to memory...\n");
	printf("text start=%.8p fileimage+test_foffset=%.8p text_length=%.8p\n", BIN_SECT_TEXT_START, fileimage + BIN_SECT_TEXT_FOFFSET, BIN_SECT_TEXT_LENGTH);
	memcpy(BIN_SECT_TEXT_START, fileimage + BIN_SECT_TEXT_FOFFSET, BIN_SECT_TEXT_LENGTH);
	memcpy(BIN_SECT_RODATA_START, fileimage + BIN_SECT_RODATA_FOFFSET, BIN_SECT_RODATA_LENGTH);
	memcpy(BIN_SECT_DATA_START, fileimage + BIN_SECT_DATA_FOFFSET, BIN_SECT_DATA_LENGTH);
	memset(BIN_SECT_PLT_START, 0xCC, BIN_SECT_PLT_LENGTH);
	free(fileimage);

	printf("Linking...\n");
	Sys_CoD4Linker();

	printf("Patching...\n");
	SetJump(0x0804844C, hook_abc);
	//Com_Memset((void*)0x08048482, 0x90, 5); // remove one asd() function
	
	printf("Set Execution Privileges...\n");
	if ( ! Sys_ProtectMemory()) {
		printf("Error: Set Execution Privileges...\n");
		return 1;
	}

	printf("Run start()...\n");
	#if BINARY == BINARY_COD2
		int (*start)(int argc, char **argv);
		*(int*)&start = 0x0804A6C0; // real start
		*(int*)&start = 0x080D4F7C; // main()
		start(0, NULL);
	#endif
	#if BINARY == BINARY_SIMPLE
		int (*start)(int argc, char **argv);
		*(int*)&start = 0x08048360; // "real" start address
		*(int*)&start = 0x08048465; // main()
		start(0, NULL);
	#endif

	printf("End start()...\n");	

	getchar();
	return 0;
}