#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	//print error if not enough parameters in command line		
	if (argc != 2)  {
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		exit(1);
	}

	//remove directory(argv[1])
	if (rmdir(argv[1]) < 0)  {
		//print error if error
		perror("rmdir");
		exit(1);
	}
}
