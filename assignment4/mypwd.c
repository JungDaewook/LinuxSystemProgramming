#include <stdio.h>
#include <unistd.h>

#define	MAX_BUF	256

main(int argc, char *argv[])
{
	char	buf[MAX_BUF];

	//get path of current directory or file in buf
	if (getcwd(buf, MAX_BUF) == NULL)  {
		//print error if error
		perror("getcwd");
		exit(1);
	}

	//print buf
	printf("%s\n", buf);
}
