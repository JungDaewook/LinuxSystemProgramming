#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int mysystem(char *cmd)
{ 
    char *argv[] = {cmd, NULL};
    pid_t pid;
	int status;

    printf("I will execute myls which is same as ls\n");
    printf("system(\"myls\"):\n");
    printf("\n");

    //fork
    if ((pid = fork()) < 0){
        //print error if error
		perror("fork");
		exit(1);
    }
    //child process
	else if(pid == 0)
	{
        //execute myls same as ls
		if (execv("/home/lsp60/assignment4/myls", argv) < 0);
            perror("execv");
		    exit(1);
		}

    //wait until child process get killed
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}

    return 0;
}


int main()
{
	int		status;

    //execute myls by mysystem
	if ((status = mysystem("myls")) < 0)  {
		perror(mysystem);
		exit(1);
	}
	printf("exit status = %d\n", status);

    return 0;
}