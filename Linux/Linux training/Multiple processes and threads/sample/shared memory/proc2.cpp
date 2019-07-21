#include <share_mem.h>
#include <sem.h>

int main(int argc, char * argv[])
{
	key_t 	key 	= SHM_KEY;	
	int 	shmflg 	= 0600;
	char 	*pShm; // share mem pointer
	
	/* get share mem id */ 
	int shmid = shmget(key, SHM_SIZE, shmflg);	

	if (shmget < 0) {
		perror("shmget");
		return 1;
	}

	/*----------------------------------------------------------------------*/
	/*					Lock Semaphore & Read data to Share memory			*/
	/*----------------------------------------------------------------------*/	
	/* lock semaphore */
	sem_lock(SEM_NAME);

	/* attach the segment to our data space */
    if ((pShm = (char*) shmat(shmid, NULL, 0)) == (char*) SHM_ERROR) {
        perror("shmat");
        return 1;
    }

    /* Now read what the proc1 put in the memory */
	printf("data in share mem : %s\n", pShm);

	/*----------------------------------------------------------------------*/
	/*					Unlock Semaphore & deattach Share memory				*/
	/*----------------------------------------------------------------------*/	
	/* Deattch share mem */
	shmdt(pShm);

	/* unlock semaphore */
	if ( !sem_unlock(SEM_NAME) )
		return 1;

	return 0;	
}
