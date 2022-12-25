#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "semlib.h"
#include "prodcons.h"

int Calc(int number)
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

	data = number;
	pBuf->buf[pBuf->in].data = data;
	pBuf->in = (pBuf->in + 1) % MAX_BUF;

	if ((emptySemid = semInit(EMPTY_SEM_KEY)) < 0)  { //semaphore 1
		fprintf(stderr, "semInit failure\n");
		exit(1);
	}
	
	if (semPost(emptySemid) < 0)  {
		fprintf(stderr, "semPost failure\n");
		exit(1);
	}

	if ((fullSemid = semInit(FULL_SEM_KEY)) < 0)  {  //SEMAPHORE 2
		fprintf(stderr, "semInit failure\n");
		exit(1);
	}


	srand(0x8888);
	if (semWait(fullSemid) < 0)  { //wait for sem2
		fprintf(stderr, "semWait failure\n");
		exit(1);
	}

	data = pBuf->buf[pBuf->out].data; //read data
	pBuf->out = (pBuf->out + 1) % MAX_BUF;

	return data;
}

int main(int argc, char *argv[]) {
	int mainNumber;
	int result;
	
	if (argc != 2) {
		perror("argc!=2");
		exit(1);
	}
	mainNumber = atoi(argv[1]);
	result = Calc(mainNumber);
	printf("Calc = %d", result);
	return 0;
}
