#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define	MAX_BUF	1024

main(int argc, char *argv[])
{
	int 	fd1, fd2, count;
	char	buf[MAX_BUF];
	
	//if argc !=3, print error
	if (argc != 3)  {
		printf("Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	//open sourc file
	//if can't open, print error
	if ((fd1 = open(argv[1], O_RDONLY)) < 0)  {
		perror("open");
		exit(1);
	}
	
	//open destination file with option O_WRONLY, O_CREAT, O_TRUNC, -rw-r--r--
	//if can't open, print error
	if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)  {
		perror("open");
		exit(1);
	}

	//read source file
	while ((count = read(fd1, buf, MAX_BUF)) > 0)  {
		//write to destination file while count>0
		write(fd2, buf, count);
	}

	//close files
	close(fd1);
	close(fd2);
}
