#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	//if not enough parameters in command line, print error
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destinaion\n", argv[0]);
		exit(1);
	}

	//make symbolic link argv[1](actualpath) to argv[2](symbolic path)
	if (symlink(argv[1], argv[2]) < 0)  {
		//print error if error
		perror("link");
		exit(1);
	}
}
