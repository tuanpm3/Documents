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
	int 	integer;

	/* Prepare a file large enough to hold an unsigned integer.  */
	fd = open (argv[1], O_RDWR, S_IRUSR | S_IWUSR);
	
	/* Create the memory mapping.  */
	mapBuf = mmap (0, FILE_LENGTH, PROT_READ, MAP_SHARED, fd, 0);
	close (fd);
	
	/* Read a integer from memory-mapped area.  */
	memcpy(&integer, mapBuf, sizeof(integer));
	
	/* Release the memory (unnecessary because the program exits).  */
	munmap (mapBuf, FILE_LENGTH);
	printf("integer = %d\n", integer);
	
	return 0;
}