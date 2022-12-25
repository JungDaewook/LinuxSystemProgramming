#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void SigChldHandler(int signo)
{
	pid_t pid;
	int status;

	//wait until child process finishes	
	pid = wait(&status);
	printf("A child killed with %d status\n", status);
	exit(0);
}

main()
{
	pid_t pid;
	int status;
	
	//giv SIGCHLD to SigChldHandler
	signal(SIGCHLD, SigChldHandler);

	//fork, print error if error
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	//child process
	else if (pid == 0)  {
		printf("I'm a child\n");
		sleep(2);
	}
	//parent process
	else  {
		while(1);
	}
}
