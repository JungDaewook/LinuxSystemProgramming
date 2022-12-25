#include <stdio.h>

#define	MAX_BUF	1024

main(int argc, char *argv[])
{
	FILE	*src1, *src2, *dst;
	char	buf[MAX_BUF];
	int		count;

	//if argc != 4 print error
	if (argc != 4)  {
		fprintf(stderr, "Usage: %s source1 source2 dest\n", argv[0]);
		exit(1);
	}

	//open first source file with option read only in binary mode
	//if can't open print error
	if ((src1 = fopen(argv[1], "rb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//open second source file with option read only in binary mode
	//if can't open print error
	if ((src2 = fopen(argv[2], "rb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//open destination file with write in binary mode
	//if can't open print error
	if ((dst = fopen(argv[3], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//read first source file
	while ((count = fread(buf, 1, MAX_BUF, src1)) > 0)  {
		//write first source file to destination file until eof
		fwrite(buf, 1, count, dst);
	}

	//read second source file 
	while ((count = fread(buf, 1, MAX_BUF, src2)) > 0)  {
		//write second source file to destination file until eof
		fwrite(buf, 1, count, dst);
	}

	//close files
	fclose(src1);
	fclose(src2);
	fclose(dst);
}
