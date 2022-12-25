#include <stdio.h>

#define	MAX_BUF	256

main(int argc, char *argv[])
{
	FILE	*src, *dst;
	char	buf[MAX_BUF];
	
	//if agrc!=3, print error
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	//open source file with option read only in text mode
	//if can't open print error
	if ((src = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//open destination file with option write mode in text mode
	//if can't open print error
	if ((dst = fopen(argv[2], "wt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//get string from source file until MAX_BUF
	while (fgets(buf, MAX_BUF, src) != NULL)  {
		//put string to destination file from source file until eof
		fputs(buf, dst);
	}

	//close files
	fclose(src);
	fclose(dst);
}
