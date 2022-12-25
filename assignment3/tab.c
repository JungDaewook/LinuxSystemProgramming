#include <stdio.h>

enum { FALSE, TRUE };

void
conv(char *fname)
{
	FILE	*src, *dst;
	char	fdest[40];
	int		ch, first;

	//open source file with option read only in text mode
	//if can't open, print error
	if ((src = fopen(fname, "rt")) == NULL)  {
		perror("fopen");
		return;
	}

	strcpy(fdest, fname);
	strcat(fdest, ".t");
	//open destination file named "fname.t" with option write in text mode
	//if can't open, print error
	if ((dst = fopen(fdest, "wt")) == NULL)  {
		perror("fopen");
		return;
	}

	first = TRUE;
	//get char of source file
	while ((ch = fgetc(src)) != EOF)  {
		//if char of source file is '\t' put 4 of ' 'in destination file
		if (first && ch == '\t')  {
			fputc(' ', dst);
			fputc(' ', dst);
			fputc(' ', dst);
			fputc(' ', dst);
		}
		else  {
			//if the char is not '\t' copy source file to destination file
			fputc(ch, dst);
			//set first = FALSE until th line ends('\n')
			if (first)
				first = FALSE;
			if (ch == '\n')
				first = TRUE;
		}
	}

	//close files
	fclose(src);
	fclose(dst);
}

main(int argc, char *argv[])
{
	while (--argc)  {
		conv(argv[argc]);
	}
}
