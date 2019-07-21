#include <sem.h>

/* semaphore control functions */
bool sem_init(const char* semName)
{
    sem_t *pSem;
    int oflag = O_CREAT;
    mode_t mode = 0644;
    unsigned int value = 1;

	// init semaphore
    pSem = sem_open(semName, oflag, mode, value);

    if(pSem == (void *)-1) {
        perror("sem_open");
        return SHM_NG;
    }
	else
		return SHM_OK;
}

bool sem_destroy(const char* semName)
{
    sem_t *pSem;
    int oflag = 0;

	// init semaphore
    pSem = sem_open(semName, oflag);

    if(pSem == (void *)-1) {
        perror("sem_open");
        return SHM_NG;
    }

	if (!sem_destroy(pSem))  {
		return SHM_OK;
	}
	else {
		perror("sem_destroy");
		return SHM_NG;
	}
}

bool sem_lock(const char* semName)
{
    sem_t *pSem;
    int oflag = 0;

	// get semaphore
    pSem = sem_open(semName, oflag);

    if(pSem == (void *)-1) {
        perror("sem_open");
        return SHM_NG;
    }
	
	// lock semaphore
	if(!sem_wait(pSem)) {
		return SHM_OK;
    } 
	else {
		perror("sem_post");
        return SHM_NG;
    }	
}

bool sem_unlock(const char* semName)
{
    sem_t *pSem;
    int oflag = 0;

	// get semaphore
    pSem = sem_open(semName, oflag);

    if(pSem == (void *)-1) {
        perror("sem_open");
        return SHM_NG;
    }
	
	// unlock semaphore
	if(!sem_post(pSem)) {
		return SHM_OK;
    } 
	else {
		perror("sem_post");
        return SHM_NG;
    }	
}