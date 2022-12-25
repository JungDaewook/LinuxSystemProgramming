#include <stdio.h>

#define	MAX_CMD		256

void
DoCmd(char *cmd)
{
	printf("Doing %s", cmd);
	sleep(1);
	printf("Done\n");
}

int main()
{
	char	cmd[MAX_CMD];
	int		pid;

	while (1)  {
		printf("CMD> ");
        //get input by user
		fgets(cmd, MAX_CMD, stdin);	
		if (cmd[0] == 'q')
			break;
        //fork
		if ((pid = fork()) < 0)  {
			perror("fork");
			exit(1);
		}
        //DoCmd in child process
		else if (pid == 0)  {
			DoCmd(cmd);
			exit(0);
		}
#if 0
		else  {
			wait(NULL);
		}
#endif
	}

    return 0;
}