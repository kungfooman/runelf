gcc -c runelf.c -o runelf.o 
gcc -g -Wl,--nxcompat,--image-base,0x8040000 loader.o
pause