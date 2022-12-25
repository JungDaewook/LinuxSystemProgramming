#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
	int 	fd;
	char	ch = '\0';

	//creat file.hole with option -r--------
	//if can't creat print error
	if ((fd = creat("file.hole", 0400)) < 0)  {
		perror("creat");
		exit(1);
	}

	//move seek pointer from the first of the file to 1023
	//if can't move print error
	if (lseek(fd, 1023, SEEK_SET) < 0)  {
		perror("lseek");
		exit(1);
	}

	//write 1 byte of ch in fd
	write(fd, &ch, 1);

	//close file
	close(fd);
}
