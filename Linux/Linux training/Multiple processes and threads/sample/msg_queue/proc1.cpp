#include <msg_queue.h>

int main(int argc, char * argv[])
{
	key_t key 	= KEY; 					/* key to be passed to msgget() */ 
	int msgflg 	= 0600 | IPC_CREAT; 	/* msgflg to be passed to msgget() */ 

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
	msg.mtype = MSG_TYPE1;
	const char* content = "message1";
	int msgSize = strlen(content) + 1;

	// send message size to queue
	memset(msg.mtext, 0, MSG_SIZE);	
	memcpy(msg.mtext, &msgSize, sizeof msgSize);
	if (msgsnd(msqid, &msg, sizeof(msgSize), ~IPC_NOWAIT) == MSG_ERROR) {
		perror("msgsnd");
		return 1;
	}
	else {
		printf("send message size success !\n");
		printf("message size = %d\n", msgSize);
	}
	
	// send message to queue
	memset(msg.mtext, 0, MSG_SIZE);	
	sprintf(msg.mtext, "%s%c", content, '\0');
	if (msgsnd(msqid, &msg, msgSize, ~IPC_NOWAIT) == MSG_ERROR) {
		perror("msgsnd");
		return 1;
	}
	else {
		printf("send message success !\n");
		printf("message : %s\n", content);
	}		

	return 0;	
}

