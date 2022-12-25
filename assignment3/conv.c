/*
텍스트 파일을 바이너리 파일로 만드는 것이 conv.c, 바이너리 파일에 접근하는 것이 access.c
*/
#include <stdio.h>
#include <string.h>
#include "record.h"

main(int argc, char *argv[])
{
	FILE	*src, *dst;
	Record	rec;

	//if argc != 3 print error
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source dest\n", argv[0]);
		exit(1);
	}

	//open source file with option read only in text mode
	//if can't open print error
	if ((src = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	//open destination file with option write in binary file
	//if can't open print error
	if ((dst = fopen(argv[2], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}
	
	//get string from source file to rec.stud
	while (fgets(rec.stud, SMAX, src))  {
		//find where NULL first appears in rec.stud
		*strchr(rec.stud, '\n') = '\0';
		//get string from source file to rec.num
		fgets(rec.num, NMAX, src);
		//find where NULL first appers in rec.num
		*strchr(rec.num, '\n') = '\0';
		//get string from source file to rec.dept
		fgets(rec.dept, DMAX, src);
		//find where NULL first appears in rec.dept
		*strchr(rec.dept, '\n') = '\0';

		//write rec to destination file
		fwrite(&rec, sizeof(rec), 1, dst);
	}

	//close files
	fclose(src);
	fclose(dst);
}
