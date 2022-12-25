#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void printFileNameAndSize(DIR *dp) {
	
    struct dirent   *dep;
    struct stat statbuf; 
    int fileSize;

    //open current directory
    if ((dp = opendir(".")) == NULL)  {
        perror("opendir");
        exit(0);
    }   

    //read directories and files in current directory
    while (dep = readdir(dp))  {
        if(lstat(dep->d_name,&statbuf)<0){
                        perror("lstat");
                        exit(1);
        }
		//file name
    	printf("%s ",dep->d_name); 
        	
		//file size
        fileSize = statbuf.st_size;
		printf("%d\n",fileSize);     
    }   

    closedir(dp);
}

int main()
{
	DIR *dp;
	pthread_t tid1;

	if(pthread_create(&tid1, NULL, (void *)printFileNameAndSize, (void *)dp)<0) {
		perror("pthread_create");
		exit(1);
	}   

	if(pthread_join(tid1,NULL)<0) {
		perror("pthread_join");
		exit(1);
	}
	return 0;
}

