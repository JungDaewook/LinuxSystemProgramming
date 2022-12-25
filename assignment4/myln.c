#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	//if argc != 3(not enough parameters) print error
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destinaion\n", argv[0]);
		exit(1);
	}

	//link argv[1](existing path) to argv[2](newpath)
	if (link(argv[1], argv[2]) < 0)  {
		//print error if error
		perror("link");
		exit(1);
	}
}
