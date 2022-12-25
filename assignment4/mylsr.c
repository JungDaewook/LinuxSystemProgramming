#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#define	MAX_PATH	256

void
JustDoIt(char *path)
{
	DIR				*dp;
	struct dirent	*dep;
	struct stat		statbuf;
	char			fullpath[MAX_PATH];

	//open directory of path
	if ((dp = opendir(path)) == NULL)  {
		//print error if error
		perror("opendir");
		exit(0);
	}

	printf("\n%s:\n", path);
	//read all directories and files from path
	while (dep = readdir(dp))  {
		//print all directories and files name from path(including . , ..)
		if (strcmp(".", dep->d_name) == 0 || strcmp("..", dep->d_name) == 0)
			continue;
		printf("%s\n", dep->d_name);
	}

	//reset the position of the directory stream to first
	rewinddir(dp);
	//read directory from path
	while (dep = readdir(dp))  {
		if (strcmp(".", dep->d_name) == 0 || strcmp("..", dep->d_name) == 0)
			continue;
		//make fullpath : (path)/dep
		strcpy(fullpath, path);
		strcat(fullpath, "/");
		strcat(fullpath, dep->d_name);
		//get stat of (path)/dep
		if (lstat(fullpath, &statbuf) < 0)  {
			//print error if error
			perror("lstat");
			exit(1);
		}
		//if statbuf is directory, read the files and directories under the statbuf by recursive call
		if (S_ISDIR(statbuf.st_mode))  {
			JustDoIt(fullpath);
		}
	}
	
	//close directory
	closedir(dp);
}

main()
{
	//JusdtDoIT about current directory
	JustDoIt(".");
}
