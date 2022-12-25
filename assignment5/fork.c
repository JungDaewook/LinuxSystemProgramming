#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int		Var = 6;
char	Buf[] = "a write to stdout\n";

int main()
{
	int		var;
	pid_t	pid;

	var = 88;
    //print "a write to stdout"
	write(STDOUT_FILENO, Buf, sizeof(Buf)-1);
	printf("Before fork\n");

    //fork
	if ((pid = fork()) < 0)  {
		//print error if error
        perror("fork");
		exit(1);
	}
    //child process
	else if (pid == 0)  {
		/* child */
		Var++;
		var++;
	}
    //parent process sleep -> later than child
	else  {
		/* parent */
		sleep(2);
	}

    //child will print his pid, Var, var first then parent will print his pid, Var,var
	printf("pid = %d, Var = %d, var = %d\n", getpid(), Var, var);
    return 0;
}