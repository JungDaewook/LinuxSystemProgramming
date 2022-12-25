#include <stdio.h>
#include <signal.h>

void
SigIntHandler(int signo)
{
	printf("Received a SIGINT signal\n");
	printf("Terminate this process\n");

	//kill process
	exit(0);
}

main()
{
	//if SIGINT signal appears, activate SigIntHandler
	signal(SIGINT, SigIntHandler);

	printf("Press ^C to quit\n");
	//if press ^c, SigIntHandler activates and kill process
	for ( ; ; )
		pause();
}
