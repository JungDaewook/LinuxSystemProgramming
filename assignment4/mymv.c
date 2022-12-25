#include <stdio.h>

main(int argc, char *argv[])
{
	//print error if not enough parameters in command line
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s old new\n", argv[0]);
		exit(1);
	}

	//rename argv[1](old name) to argv[2](new name)
	if (rename(argv[1], argv[2]) < 0)  {
		//print error if error
		perror("rename");
		exit(1);
	}
}
