#include <stdio.h>

#define	MAX_BUF	256

main(int argc, char *argv[])
{
	FILE	*fp;
	char	buf[MAX_BUF];
	int		line;

	//if argc !=2, print error
	if (argc != 2)  {
		printf("Usage: %s filename\n", argv[0]);
		exit(1);
	}

	//open file with option rt(read only in text mode)
	//if can't open print error
	if ((fp = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	
	line = 1;
	
	//get string from fp(argv[1]) from buf to MAX_BUF
	while (fgets(buf, MAX_BUF, fp))  {
		//print string of fp(argv[1]) until eof
		printf("%4d: %s", line++, buf);
	}

	//close file
	fclose(fp);
}
