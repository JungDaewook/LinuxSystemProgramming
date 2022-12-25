#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void
CharAtaTime(char *str)
{
	char	*ptr;
	int		c, i;

    //set stdout as NULL
	setbuf(stdout, NULL);
    //print str in a complex for loop for race condition
	for (ptr = str ; c = *ptr++ ; )  {
		for(i = 0 ; i < 999999 ; i++)
			;
		putc(c, stdout);
	}
}

main()
{
	pid_t	pid;

    //fork
	if ((pid = fork()) < 0)  {
        //print error if error
		perror("fork");
		exit(1);
	}
    //child process
	else if (pid == 0)  {
		CharAtaTime("output from child\n");
	} 
    //parent process
	else  {
        //wait until child get killed to solve race condition
		wait(NULL);
		CharAtaTime("output from parent\n");
	}
}