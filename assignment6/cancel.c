#include <stdio.h>
#include <signal.h>
#include <pthread.h>

pthread_t	ThreadId[2];

void
SigIntHandler(int signo)
{
	int		i;

	//print thread id which sent SIGINT
	printf("Received a SIGINT signal by thread %d\n", pthread_self());
	//print both of the thread ids
	printf("Terminate other threads: tid=%d, %d\n", ThreadId[0], ThreadId[1]);

	//cancel all threads
	//print error if error
	for (i = 0 ; i < 2 ; i++)  {
		if (pthread_cancel(ThreadId[i]))  {
			perror("pthread_cancel");
			exit(1);
		}
	}
	//wait until all threads terminate
	//print error if error
	for (i = 0 ; i < 2 ; i++)  {
		if (pthread_join(ThreadId[i], NULL))  {
			perror("pthread_join");
			exit(1);
		}
	}
	printf("Threads terminated: tid=%d, %d\n", ThreadId[0], ThreadId[1]);

	exit(0);
}

void
Thread1(void *dummy)
{
	//print thread id
	printf("Thread %d created.....\n", pthread_self());

	//set cancelstate of thread to PTHREAD_CANCEL_ENABLE
	//the thread is cancelable
	if (pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL))  {
		perror("pthread_setcancelstate");
		pthread_exit(NULL);
	}
	//set cancletype to PTHREAD_CANCEL_ASYNCHRONOUS
	//the thread can be canceled anytime
	if (pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL))  {
		perror("pthread_setcanceltype");
		pthread_exit(NULL);
	}

	while (1)
		;
}

void
Thread2(void *dummy)
{
	//print thread id
	printf("Thread %d created.....\n", pthread_self());

	//set cancelstate of thread to PTHREAD_CANCEL_ENABLE
	//the thread is cancelable
	if (pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL))  {
		perror("pthread_setcancelstate");
		pthread_exit(NULL);
	}
	//set cancletype to PTHREAD_CANCEL_ASYNCHRONOUS
	//the thread can be canceled anytime
	if (pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL))  {
		perror("pthread_setcanceltype");
		pthread_exit(NULL);
	}

	while (1)
		;
}

main()
{
	//create thread 1
	if (pthread_create(&ThreadId[0], NULL, (void *)Thread1, NULL) < 0)  {
		perror("pthread_create");
		exit(1);
	}
	//create thread 2
	if (pthread_create(&ThreadId[1], NULL, (void *)Thread2, NULL) < 0)  {
		perror("pthread_create");
		exit(1);
	}

	//if SIGINT signal appears, activate SigIntHandler
	signal(SIGINT, SigIntHandler);

	printf("Press ^C to quit\n");

	for ( ; ; )
		pause();
}
