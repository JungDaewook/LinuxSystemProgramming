#include <stdio.h>

main(int argc, char *argv[])
{
	FILE	*src, *dst;
	int		ch;

	//if argc !=3 print error
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	//open source file(argv[1]) in option rt(read mode in text mode)
	//if can't open print error
	if ((src = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//open destination file(argv[2]) in option wt(write mode in text mode)
	//if can't open print error
	if ((dst = fopen(argv[2], "wt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	//get char from source file
	while ((ch = fgetc(src)) != EOF)  {
		//put char to destination file from source file until eof of source file
		fputc(ch, dst);
	}

	//close files
	fclose(src);
	fclose(dst);
}
