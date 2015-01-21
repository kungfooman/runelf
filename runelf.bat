gcc -c runelf.c -o runelf.o -m32
gcc -g -Wl,--nxcompat,--image-base,0x8040000 runelf.o -Tlinkerscript_win32.ld -o runelf.exe -lm -lws2_32 -lwsock32 -lwinmm -static-libgcc

pause