#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#define FILE_LENGTH 32

int main (int argc, char* const argv[])
{
	int 	fd;
	void* 	mapBuf;
	int 	x = 10;
	
	/* Prepare a file large enough to hold an unsigned integer.  */
	fd = open (argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	lseek (fd, FILE_LENGTH+1, SEEK_SET);
	write(fd, "", 1);
	lseek(fd, 0, SEEK_SET);
	
	/* Create the memory mapping.  */
	mapBuf = mmap (0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
	close (fd);
	
	/* Write a integer to memory-mapped area.  */	
	memcpy(mapBuf, (const void*) &x, sizeof(x));

	/* Release the memory (unnecessary because the program exits).  */
	munmap (mapBuf, FILE_LENGTH);
	return 0;
}