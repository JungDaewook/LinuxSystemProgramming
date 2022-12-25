#include <stdio.h>
#include <stdlib.h>

int main()
{
	int		status;

    //execute date in command line
	if ((status = system("date")) < 0)  {
		perror("system");
		exit(1);
	}
	printf("exit status = %d\n", status);

    //execute nosuchcommand in command line
	if ((status = system("nosuchcommand")) < 0)  {
		perror("system");
		exit(1);
	}
	printf("exit status = %d\n", status);

    //execute who; exit 44 command line
	if ((status = system("who; exit 44")) < 0)  {
		perror("system");
		exit(1);
	}
	printf("exit status = %d\n", status);
    
    return 0;
}