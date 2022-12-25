#include <stdio.h>
#include <stdlib.h>

void
myexit1()
{
	printf("first exit handler\n");
}

void
myexit2()
{
	printf("second exit handler\n");
}

main()
{
    //causes function myexit2 when program terminates
	if (atexit(myexit2) != 0)  {
        //print error if error
		perror("atexit");
		exit(1);
	}

    //causes function myexit2 when program terminates
	if (atexit(myexit1) != 0)  {
        //print error if error
		perror("atexit");
		exit(1);
	}

    //causes function myexit1 when program terminates
	if (atexit(myexit1) != 0)  {
        //print error if error
		perror("atexit");
		exit(1);
	}

	printf("main is done\n");
}