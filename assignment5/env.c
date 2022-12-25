#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int			i;
	char		**p;
	extern char	**environ;

	printf("List command-line arguments\n");
    //print list of command-line arguements
	for (i = 0 ; i < argc ; i++)  {
		printf("%s\n", argv[i]);
	}

	printf("\n");
	printf("List environment variables from environ variable\n");
    //print list of environment variables from environ variable
	for (p = environ ; *p != NULL ; p++)  {
		printf("%s\n", *p);
	}

	printf("\n");
	printf("List environment variables from envp variable\n");
    //prinnt list of environment variables from envp variable
	for (p = envp ; *p != NULL ; p++)  {
		printf("%s\n", *p);
	}
    
    return 0;
}