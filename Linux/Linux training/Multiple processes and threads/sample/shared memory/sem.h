#ifndef SHM_SEM_H_
#define SHM_SEM_H_

#include <share_mem.h>
#include <fcntl.h> 		/* For O_* constants */
#include <semaphore.h>

/* semaphore control functions */
bool sem_init(const char* semName);
bool sem_destroy(const char* semName);
bool sem_lock(const char* semName);
bool sem_unlock(const char* semName);

#endif /* SHM_SEM_H_ */
