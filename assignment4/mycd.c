#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	//print error if not enough parameters in command line
	if (argc != 2)  {
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		exit(1);
	}

	//change directory to argv[1]
	if (chdir(argv[1]) < 0)  {
		//print error if error
		perror("chdir");
		exit(1);
	}
}
