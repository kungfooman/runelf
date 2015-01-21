#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <setjmp.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <inttypes.h>
#include <direct.h>
#include <windows.h>

/*
==================
Dummy functions just to get it compiled
==================
*/
void* dlopen(const char* dl, int mode){
	return NULL;
}

const char* dlerror(){
	return NULL;
}

void dlclose(void* handle){


}

void* dlsym(void* handle, const char* proc){
	return NULL;
}

struct lnx_stat
{
	uint64_t      st_dev;      /* Device */
	uint32_t      st_pad1;
	uint32_t      st_ino;      /* INode */
	uint32_t      st_mode;     /* Zugriffsrechte */
	uint32_t      st_nlink;    /* Anzahl harter Links */
	uint32_t      st_uid;      /* UID des Besitzers */
	uint32_t      st_gid;      /* GID des Besitzers */
	uint64_t      st_rdev;     /* Typ (wenn INode-Gerät) */
	uint32_t      st_pad2;
	uint32_t      st_size;     /* Größe in Bytes*/
	uint32_t      st_blksize;  /* Blockgröße */
	uint32_t      st_blocks;   /* Allozierte Blocks */
	/* Who cares ? */
//	struct timespec st_atim;    /* Letzter Zugriff */
//	struct timespec st_mtim;    /* Letzte Modifikation */
//	struct timespec st_ctim;    /* Letzte Aenderung */
};

int ___xstat(int __ver, const char *__filename, struct lnx_stat *__stat_buf)
{
	__stat_buf->st_dev = 0;
	__stat_buf->st_ino = 0;	
	__stat_buf->st_mode = 0;	
	__stat_buf->st_nlink = 0;	
	__stat_buf->st_uid = 0;	
	__stat_buf->st_gid = 0;	
	__stat_buf->st_rdev = 0;
	__stat_buf->st_size = 0;
	
	HANDLE hFile = CreateFile((LPCTSTR)__filename, 
						GENERIC_READ,
						FILE_SHARE_READ,
						NULL,
						OPEN_EXISTING,
						FILE_FLAG_OVERLAPPED | FILE_FLAG_NO_BUFFERING,
						NULL );
	
	if( hFile == INVALID_HANDLE_VALUE )
	{
		return -1;
	}
	__stat_buf->st_size = GetFileSize(hFile, NULL);

	CloseHandle(hFile);
	return 0;
}

/*
	Windows _stat() function seems not to work. As this was only used to retrive the filesize we only pass this
*/

int ___fxstat(int __ver, int __filedesc, struct lnx_stat *__stat_buf)
{
	__stat_buf->st_dev = 0;
	__stat_buf->st_ino = 0;	
	__stat_buf->st_mode = 0;	
	__stat_buf->st_nlink = 0;	
	__stat_buf->st_uid = 0;	
	__stat_buf->st_gid = 0;	
	__stat_buf->st_rdev = 0;	
	__stat_buf->st_size = _filelength( __filedesc );	

	if(__stat_buf->st_size == -1)
		return -1;
	else
		return 0;
}


void* __cdecl _memalign(int align, int numbytes)
{/* This can cause crash */
    return calloc(1, numbytes + align);
}

int* __cdecl ___errno_location()
{
    static int _errorno = 0;
    return &_errorno;
}




int Q_stricmpn (const char *s1, const char *s2, int n) {
	int		c1, c2;

        if ( s1 == NULL ) {
           if ( s2 == NULL )
             return 0;
           else
             return -1;
        }
        else if ( s2==NULL )
          return 1;


	
	do {
		c1 = *s1++;
		c2 = *s2++;

		if (!n--) {
			return 0;		// strings are equal until end point
		}
		
		if (c1 != c2) {
			if (c1 >= 'a' && c1 <= 'z') {
				c1 -= ('a' - 'A');
			}
			if (c2 >= 'a' && c2 <= 'z') {
				c2 -= ('a' - 'A');
			}
			if (c1 != c2) {
				return c1 < c2 ? -1 : 1;
			}
		}
	} while (c1);
	
	return 0;		// strings are equal
}

int Q_strncmp (const char *s1, const char *s2, int n) {
	int		c1, c2;
	
	do {
		c1 = *s1++;
		c2 = *s2++;

		if (!n--) {
			return 0;		// strings are equal until end point
		}
		
		if (c1 != c2) {
			return c1 < c2 ? -1 : 1;
		}
	} while (c1);
	
	return 0;		// strings are equal
}

int Q_stricmp (const char *s1, const char *s2) {
	return (s1 && s2) ? Q_stricmpn (s1, s2, 99999) : -1;
}