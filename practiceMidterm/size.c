/*
현재의 directory에서 file의 크기가 특정 크기 (command-line argument로 주어짐) 이상인
프로그램의 이름을 출력하는 프로그램 ‘size’를 작성하시오. Source file은 ‘size.c’로 할 것. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

main(int argc, char *argv[])
{
	for (int i = 0; i< argc; i++){
		printf("argv[%d]=%s\n", i, argv[i]);
	}
	if (argc != 2) {
		printf("not enough arguements");
		exit(1);
	}
	
	DIR				*dp;
	struct dirent	*dep;
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

    	//file size
		fileSize = statbuf.st_size;

		int inputFileSize = atoi(argv[1]);
		if(fileSize >= inputFileSize) {		
    		//file name 
    		printf("%s\n", dep->d_name); 
		}
	}

	closedir(dp);
}
