#include <stdio.h>
#include <unistd.h>
#include "record.h"

void
print_record(Record *rp)
{
	puts(rp->stud);
	puts(rp->num);
	puts(rp->dept);
}

main(int argc, char *argv[])
{
	FILE	*fp;
	Record	rec;

	//if argc != 2, print error
	if (argc != 2)  {
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(1);
	}

	//open argv[1] with option read only in binary file
	//if can't open print error
	if ((fp = fopen(argv[1], "r+b")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	printf("-----Ordered Record List-----\n");

	//read argv[1] to rec
	while (fread(&rec, sizeof(rec), 1, fp))  {
		//print rec until eof of fp
		print_record(&rec);
	}
	//move file pointer to first
	rewind(fp);
	getchar();

	printf("-----Shuffled Record List-----\n");

	//move file pointer from first to sizeof(rec) * 2bytes
	fseek(fp, sizeof(rec)*2L, SEEK_SET);
	//read fp to rec
	fread(&rec, sizeof(rec), 1, fp);
	//print rec
	print_record(&rec);

	//move file pointer from first to sizeof(rec) * 5bytes
	fseek(fp, sizeof(rec)*5L, SEEK_SET);
	//read fp to rec
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);

	//move file pointer from first to sizeof(rec) * 1bytes
	fseek(fp, sizeof(rec)*1L, SEEK_SET);
	//read fp to rec
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);

	//move file pointer from first to sizeof(rec) * 3bytes
	fseek(fp, sizeof(rec)*3L, SEEK_SET);
	//read fp to rec
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);

	//move file pointer from first to sizeof(rec) * 0bytes
	fseek(fp, sizeof(rec)*0L, SEEK_SET);
	//read fp to rec
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);

	//move file pointer from first to sizeof(rec) * 4bytes
	fseek(fp, sizeof(rec)*4L, SEEK_SET);
	//read fp to rec
	fread(&rec, sizeof(rec), 1, fp);
	print_record(&rec);
	getchar();

	printf("-----Updated Record List-----\n");

	//move file pointer from first to sizeof(rec) * 2bytes
	fseek(fp, sizeof(rec)*2L, SEEK_SET);
	//read fp to rec
	fread(&rec, sizeof(rec), 1, fp);
	strcpy(rec.dept, "Movie");
	fseek(fp, sizeof(rec)*2L, SEEK_SET);
	//write fp to rec
	fwrite(&rec, sizeof(rec), 1, fp);

	//move file pointer from first to sizeof(rec) * 5bytes
	fseek(fp, sizeof(rec)*5L, SEEK_SET);
	//read fp to rec
	fread(&rec, sizeof(rec), 1, fp);
	strcpy(rec.dept, "Baseball");
	fseek(fp, sizeof(rec)*5L, SEEK_SET);
	fwrite(&rec, sizeof(rec), 1, fp);

	//move file pointer to firsr
	rewind(fp);
	//read fp to rec
	while (fread(&rec, sizeof(rec), 1, fp))  {
		//print rec
		print_record(&rec);
	}

	//close file
	fclose(fp);
}
