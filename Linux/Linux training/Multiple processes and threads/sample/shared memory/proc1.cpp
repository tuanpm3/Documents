#include <share_mem.h>
#include <sem.h>

int main(int argc, char * argv[])
{
	key_t 	key 	= SHM_KEY;	
	int 	shmflg 	= 0600 | IPC_CREAT;
	char 	*pShm; // share mem pointer
	const char* data = "proc1_data";

	/*----------------------------------------------------------------------*/
	/*					Init Share Memory & Semaphore						*/
	/*----------------------------------------------------------------------*/	
	/* register share mem */ 
	int shmid = shmget(key, SHM_SIZE, shmflg);	

	if (shmget < 0) {
		perror("shmget");
		return 1;
	}
	else {
		printf("shmid = %d\n", shmid);
	}

	/* init semaphore */
	if ( !sem_init(SEM_NAME) )
		return 1;

	/*----------------------------------------------------------------------*/
	/*					Lock Semaphore & Write data to Share memory			*/
	/*----------------------------------------------------------------------*/	
	/* lock semaphore */
	sem_lock(SEM_NAME);
	
	/* attach the segment to our data space */
    if ((pShm = (char*) shmat(shmid, NULL, 0)) == (char*) SHM_ERROR) {
        perror("shmat");
        return 1;
    }

    /* Now put some things into the memory for the other process to read */
	strcpy(pShm, data);

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

