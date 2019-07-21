#ifndef MSG_QUEUE_H_
#define	MSG_QUEUE_H_

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h>

#define KEY 		1234
#define MSG_SIZE	4*1024
#define	MSG_TYPE1	1
#define	MSG_TYPE2	2
#define MSG_ERROR	-1

// message structure
struct my_msg_st {
    long mtype;
    char mtext[MSG_SIZE];
};

#endif /* MSG_QUEUE_H_ */