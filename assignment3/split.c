#include <stdio.h>
#include <unistd.h>

#define	MAX_BUF	1024

long
filesize(FILE *fp)
{
	long	cur, size;

	cur = ftell(fp);
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	fseek(fp, cur, SEEK_SET);
	return(size);
}

main(int argc, char *argv[])
{
	FILE	*src, *dst1, *dst2;
	char	buf[MAX_BUF];
	int		count, size;

	//if argc != 4 print error
	if (argc != 4)  {
		fprintf(stderr, "Usage: %s source dest1 dest2\n", argv[0]);
		exit(1);
	}

	//open source file with option read only in binary mode
	//if can't open print error
	if ((src = fopen(argv[1], "rb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//open first destination file with option write in binary mode
	//if can't open print error
	if ((dst1 = fopen(argv[2], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//open second destination file with option write in binary mode
	//if can;t print error
	if ((dst2 = fopen(argv[3], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	size = filesize(src) / 2;

	while (size > 0)  {
		count = (size > MAX_BUF) ?  MAX_BUF : size;
		//read source file until it reads half of the file(size = filesize(src)/2)
		fread(buf, 1, count, src); 
		//write half of the source file to first destination file
		fwrite(buf, 1, count, dst1);
		//reduce count from size to end the loop if size=0
		size -= count;
	}
	
	//read the other half of source file
	while ((count = fread(buf, 1, MAX_BUF, src)) > 0)  {
		//write the other half of source file to second destination file
		fwrite(buf, 1, count, dst2);
	}

	//close files
	fclose(src);
	fclose(dst1);
	fclose(dst2);
}
