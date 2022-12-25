#include <stdio.h>

#define	MAX_BUF	1

match() {
}

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


	int i = 0;

	//read source file from 1 to MAX_BUF
	while ((count = fread(buf, 1, MAX_BUF, src)) > 0)  {
		if (match(buf, argv[2]) {
			matched++;
			}
	}
	
	//close files
	fclose(src);
}
