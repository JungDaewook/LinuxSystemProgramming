#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

main()
{
	DIR				*dp;
	struct dirent	*dep;
	struct stat statbuf; 

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

    	//permission data/nlink 
    	printf((S_ISDIR(statbuf.st_mode)) ? "d" : "-"); 
    	printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
    	printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
    	printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
    	printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
	    printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
    	printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
    	printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
    	printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
    	printf((statbuf.st_mode & S_IXOTH) ? "x " : "- ");
    	printf("%li ", statbuf.st_nlink);

    	//group and user data 
    	struct passwd *pw; 
    	struct group *gid; 
    	pw = getpwuid(statbuf.st_uid);  
        printf("%s ", pw->pw_name); 
    
    	gid = getgrgid(statbuf.st_gid);
       	printf("%s ", gid->gr_name); 

    	//file size
    	printf("%5ld ", statbuf.st_size);

    	//timestamp
    	struct tm *tmp;
    	char outstr[200];
    	time_t t = statbuf.st_mtime;
    	tmp = localtime(&t);   
    	if(tmp == NULL) {
        	perror("localtime"); 
        	exit(EXIT_FAILURE);
    	} 
    	strftime(outstr, sizeof(outstr), "%b %d %R", tmp); 
    	printf("%s ", outstr);

    	//file name 
    	printf("%s\n", dep->d_name); 
		}
	
	//close current directory
	closedir(dp);
}
