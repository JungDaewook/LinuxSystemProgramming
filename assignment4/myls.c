#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

main()
{
	DIR				*dp;
	struct dirent	*dep;

	//open current directory
	if ((dp = opendir(".")) == NULL)  {
		perror("opendir");
		exit(0);
	}

	//read directories and files in current directory
	while (dep = readdir(dp))  {
		//print directory and file name
		printf("%s\n", dep->d_name);
	}
	
	//close current directory
	closedir(dp);
}
