#include <stdlib.h>
#include <string.h> 
#include <errno.h>

void print_error(char *this, char *filenamel, char *filename2){
//	fprintf(stderr, "%s cannot move %s to %s\n%s\n",
//		this, filenamel, filename2, strerror(errno));

	exit(EXIT_FAILURE);
}
void print_usage(char *this) {
//	fprint(stderr, "SYNTAX ERROR: \nUsage %s [old_filename] [new_filename]", this);
	
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv []){
	errno = 0;
	if(argc == 3){
		if (rename(argv[1], argv[2]) == -1){
			print_error(argv[0], argv[1], argv[2]);
		}
	}
	else{
		print_usage(argv[0]);
	}
	return 0;
}
