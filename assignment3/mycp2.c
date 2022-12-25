#include <stdio.h>

#define	MAX_BUF	1024

main(int argc, char *argv[])
{
	FILE	*src, *dst;
	char	buf[MAX_BUF];
	int		count;

	//if argc != 3, print error
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	//open source file with option read only in binary mode
	//if can't open print error
	if ((src = fopen(argv[1], "rb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//open destination file with option write mode in binary mode
	//if can't open print error
	if ((dst = fopen(argv[2], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//read source file from 1 to MAX_BUF
	while ((count = fread(buf, 1, MAX_BUF, src)) > 0)  {
		//write to destination file to source file until eof
		fwrite(buf, 1, count, dst);
	}
	
	//close files
	fclose(src);
	fclose(dst);
}
