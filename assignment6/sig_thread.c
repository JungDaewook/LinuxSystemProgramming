#include <stdio.h>
#include <signal.h>
#include <pthread.h>

#define	THREAD_MAIN
/*
#define	THREAD_1
#define	THREAD_2
*/


void
SigIntHandler(int signo)
{
	//print thread id that send SIGINT
	printf("Received a SIGINT signal by thread %d\n", pthread_self());
	printf("Terminate this process\n");
	
	//kill thread
	exit(0);
}

void
Thread1(void *dummy)
{
#ifdef	THREAD_1
	//if SIGINT signal appears, activate SigIntHandler
	signal(SIGINT, SigIntHandler);
#endif

	while (1)
		;
}

void
Thread2(void *dummy)
{
#ifdef	THREAD_2
	//if SIGINT signal appears, activate SigIntHandler
	signal(SIGINT, SigIntHandler);
#endif

	while (1)
		;
}

main()
{

	pthread_t	tid1, tid2;

	//create thread 1
	//if fail, print error
	if (pthread_create(&tid1, NULL, (void *)Thread1, NULL) < 0)  {
		perror("pthread_create");
		exit(1);
	}
	//create thread 2
	//if fail, print error
	if (pthread_create(&tid2, NULL, (void *)Thread2, NULL) < 0)  {
		perror("pthread_create");
		exit(1);
	}
	//print both thread ids
	printf("Create two threads: tid1=%d, tid2=%d\n", tid1, tid2);
	//print main thread id
	//the main thread activates signalhandler
	printf("Main thread: tid=%d\n", pthread_self());

#ifdef	THREAD_MAIN
	//if SIGINT signal appears, activate SigIntHandler
	signal(SIGINT, SigIntHandler);
#endif

	printf("Press ^C to quit\n");

	for ( ; ; )
		pause();
}