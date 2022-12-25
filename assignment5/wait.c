#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

main()
{
	pid_t	pid;
	int		status;

    //fork
	if ((pid = fork()) < 0)  {
        //print error if error
		perror("fork");
		exit(1);
	}
    //child process
	else if (pid == 0)  {
		printf("I'm a child\n");
		sleep(2);
	}
    //wait until child process get killed
	else  {
		wait(&status);
		printf("A child killed with %d status\n", status);
	}
}