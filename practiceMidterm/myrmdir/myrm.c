#include <stdio.h>

main(int argc, char *argv[]) {
	int i;
	if (argc == 1) {
		perror("argc == 1");
		exit(1);
	}
	for (i = 0; i < argc; i++) {
		if(remove(argv[i]) < 0) {
			perror("remove");
			exit(1);
		} 
	}
}
