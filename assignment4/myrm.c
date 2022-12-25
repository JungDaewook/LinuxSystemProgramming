#include <stdio.h>

main(int argc, char *argv[])
{
	int		i;

	//if not enough parameters in command line, print error
	if (argc == 1)  {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}

	//for the numbers of the parameters in command line(argc) remove!
	for (i = 1 ; i < argc ; i++)  {
		//remove all parameters in command line
		if (remove(argv[i]) < 0)  {
			//print error if error
			perror("remove");
			exit(1);
		}
	}
}
