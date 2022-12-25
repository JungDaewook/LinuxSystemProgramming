#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int		pid;
    //fork with pid
	if ((pid = fork()) < 0)  {
        //print error if error
		perror("fork");
		exit(1);
	}
    //child process
	else if (pid == 0)  {
		/* child */
		printf("I am %d. My parent is %d.\n", getpid(), getppid());
	}
    //parent process
	else  {
		/* parent */
		printf("I am %d. My child is %d.\n", getpid(), pid);
	}
    return 0;
}