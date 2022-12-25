#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include "semlib.h"
#include "prodcons.h"

void SigIntHandler(int signo){
	exit(0);
}

main()
{
	BoundedBufferType	*pBuf;
	int					shmid, i, data;
	int					emptySemid, fullSemid, mutexSemid;

	if ((shmid = shmget(SHM_KEY, SHM_SIZE, SHM_MODE)) < 0)  {
		perror("shmget");
		exit(1);
	}
	if ((pBuf = (BoundedBufferType *)shmat(shmid, 0, 0)) == (void *) -1)  {
		perror("shmat");
		exit(1);
	}

	if ((emptySemid = semInit(EMPTY_SEM_KEY)) < 0)  {  //SEMAPHORE 1
		fprintf(stderr, "semInit failure\n");
		exit(1);
	}
	if ((fullSemid = semInit(FULL_SEM_KEY)) < 0)  {  //SEMAPHORE 2
		fprintf(stderr, "semInit failure\n");
		exit(1);
	}
	
	if (semInitValue(emptySemid, MAX_BUF) < 0)  {
		fprintf(stderr, "semInitValue failure\n");
		exit(1);
	}
	if (semInitValue(fullSemid, 0) < 0)  {
		fprintf(stderr, "semInitValue failure\n");
		exit(1);
	}
	
	signal(SIGINT, SigIntHandler);
	
	while(1){	
		semWait(emptySemid);
		
		srand(0x9999);

	
		data = pBuf->buf[pBuf->out].data;
		pBuf->out = (pBuf->out + 1) % MAX_BUF;

		int result = 0;
		for (i = 0; i <= data; i++) {
			result += i;
		}
	
		pBuf->buf[pBuf->in].data = result;
		pBuf->in = (pBuf->in + 1) % MAX_BUF;
	
		printf("Calc = %d\n", result);
		
		semPost(fullSemid);
	
		semWait(emptySemid);
		}
	
	if (semDestroy(emptySemid) < 0)  {
		fprintf(stderr, "semDestroy failure\n");
	}

	if (semDestroy(fullSemid) < 0)  {
		fprintf(stderr, "semDestroy failure\n");
	}

	if (shmctl(shmid, IPC_RMID, 0) < 0)  {
		perror("shmctl");
		exit(1);
	}
}
