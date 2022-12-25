#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

main()
{
	//make file permission to 0666
	umask(0);
	//creat "bar" file in option -rw-rw-rw-
	if (creat("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | 
				S_IROTH | S_IWOTH) < 0)  {
		//print error if error
		perror("creat");
		exit(1);
	}
	
	//make file permission to  0600
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	//create "foo" file in option 0666 & 0600 -> 0600
	if (creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | 
				S_IROTH | S_IWOTH) < 0)  {
		//print error if error
		perror("creat");
		exit(1);
	}
}
