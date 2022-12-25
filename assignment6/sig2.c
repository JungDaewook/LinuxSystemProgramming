#include <stdio.h>
#include <signal.h>

void
SigUsrHandler(int signo)
{
	//if SIGUSR1 appears print
	if (signo == SIGUSR1)  {
		printf("Received a SIGUSR1 signal\n");
	}
	//if SIGUSR2 appears, print
	else if (signo == SIGUSR2)  {
		printf("Received a SIGUSR2 signal\n");
	}
	//is any other signal appears, print and kill process
	else  {
		printf("Received unknown signal\n");
		printf("Terminate this process\n");
		exit(0);
	}
}

main()
{
	//if SIGUSR1 appears, activate SigUsrHandler
	//if fail, print error
	if (signal(SIGUSR1, SigUsrHandler) == SIG_ERR)  {
		perror("signal");
		exit(1);
	}

	//if SIGUSR2 appears, activate SigUsrHandler
	//if fail, print error
	if (signal(SIGUSR2, SigUsrHandler) == SIG_ERR)  {
		perror("signal");
		exit(1);
	}

	for ( ; ; )
		pause();
}
