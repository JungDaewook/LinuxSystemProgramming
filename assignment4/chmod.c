#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

main()
{
	struct stat	statbuf;

	//get status of file "bar"
	if (stat("bar", &statbuf) < 0)  {
		//print error if error
		perror("stat");
		exit(1);
	}

	//turn of the permission of write in group option or set effective user id at execution time
	if (chmod("bar", (statbuf.st_mode & ~S_IWGRP) | S_ISUID) < 0)  {
		//print error if error
		perror("chmod");
		exit(1);
	}

	//chage mode of "foo" file to -rw-r--r--
	if (chmod("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)  {
		//print error if error
		perror("chmod");
		exit(1);
	}
}
