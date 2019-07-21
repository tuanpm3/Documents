#include <msg_queue.h>

int main(int argc, char * argv[])
{
	key_t key 	= KEY; 		/* key to be passed to msgget() */ 
	int msgflg 	= 0600;  

	/* get msg queue ID */ 
	int msqid = msgget(key, msgflg);	

	if (msqid == MSG_ERROR) {
		perror("msgget");
		return 1;
	}
	else {
		printf("msqid : %d\n", msqid);
	}

	my_msg_st msg;
	int msgSize;
	
	// recv msg size
	memset(msg.mtext, 0, MSG_SIZE);	
	if (msgrcv(msqid, &msg, sizeof msgSize, MSG_TYPE1, 0) == MSG_ERROR) {
		perror("msgrcv");
		return 1;
	}

	memcpy(&msgSize, msg.mtext, sizeof msgSize);
	printf("message size = %d\n", msgSize);
	memset(msg.mtext, 0, MSG_SIZE);			

	// recv msg content
	if (msgrcv(msqid, &msg, msgSize, MSG_TYPE1, 0) == MSG_ERROR) {
		perror("msgrcv");
		return 1;
	}
	else {
		printf("recv message success !\n");
		printf("message : %s\n", msg.mtext);
	}	

	return 0;	
}
