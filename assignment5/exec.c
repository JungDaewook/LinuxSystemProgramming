#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t	pid;
	char	*argv[] = { "myls", NULL };

	// execl
    //fork
	if ((pid = fork()) < 0)  {
        //print error if error
		perror("fork");
		exit(1);
	}
	else if (pid == 0)  {
        //execute myls in /home/lsp60/assignment4/myls (arguement : list)
        printf("myls by execl:\n");
        printf("\n");
		if (execl("/home/lsp60/assignment4/myls",
				"myls", NULL) < 0)  {
			perror("execl");
			exit(1);
		}
	}
    //wait until the replace process get killed
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}

	// execv
    //fork
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
    //execute myls in /home/lsp60/assignment4/myls (arguement : vector)
	else if (pid == 0)  {
        printf("myls by execv:\n");
        printf("\n");
		if (execv("/home/lsp60/assignment4/myls", argv) < 0)  {
			perror("execv");
			exit(1);
		}
	}
    //wait until replace process get killed
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}

	// execlp
    //fork
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
    //execute ./env where env exists (arguement : list path)
	else if (pid == 0)  {
        printf("env by execlp:\n");
        printf("\n");
		if (execlp("env", "env", NULL) < 0)  {
			perror("execlp");
			exit(1);
		}
	}
    //wait until replace process get killed
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}

    return 0;
}