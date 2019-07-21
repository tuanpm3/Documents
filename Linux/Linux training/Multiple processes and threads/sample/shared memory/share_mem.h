#ifndef SHM_H_
#define	SHM_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h>

#define SHM_KEY 	1234
#define SHM_SIZE	1024
#define SHM_ERROR	-1
#define SEM_NAME	"SEM_1"

#define SHM_OK 		true
#define SHM_NG 		false

#endif /* SHM_H_ */