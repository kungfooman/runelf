
gcc simple.c -o simple.elf -m32
objdump -x simple.elf > objdump_simple.txt


php parse_sections.php objdump_simple.txt

# 
# // file = objdump_simple.txt
# 
# #define BIN_SECT_PLT_START      (void *)0x08048310
# #define BIN_SECT_PLT_LENGTH             0x00000050
# #define BIN_SECT_TEXT_START     (void *)0x08048360
# #define BIN_SECT_TEXT_LENGTH            0x000001b0
# #define BIN_SECT_TEXT_FOFFSET           0x00000360
# #define BIN_SECT_RODATA_START   (void *)0x08048528
# #define BIN_SECT_RODATA_LENGTH          0x00000025
# #define BIN_SECT_RODATA_FOFFSET         0x00000528
# #define BIN_SECT_DATA_START     (void *)0x08049710
# #define BIN_SECT_DATA_LENGTH            0x00000008
# #define BIN_SECT_DATA_FOFFSET           0x00000710
# #define BIN_SECT_BSS_START      (void *)0x08049718
# #define BIN_SECT_BSS_LENGTH             0x00000004
# 
# #define BIN_START_ADRESS                0x08048360
#


objdump -T simple.elf | grep "DF \*UND\*"

# 
# 00000000      DF *UND*  00000000  GLIBC_2.0   printf
# 00000000      DF *UND*  00000000  GLIBC_2.0   puts
# 00000000      DF *UND*  00000000  GLIBC_2.0   __libc_start_main
# 