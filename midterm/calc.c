#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
	int result;
	
	if(argc == 1) {
		perror("argc ==1");
		exit(1);
	}
	
	if (*argv[2] == '+'){
		result = atoi(argv[1])+atoi(argv[3]);
		printf("%d\n",result);
		return 0;
	}

	else if (*argv[2] == '-'){
		result = atoi(argv[1])-atoi(argv[3]);
		printf("%d\n",result);
		return 0;
	}

	else if (*argv[2] == 'x'){
		result = atoi(argv[1])*atoi(argv[3]);
		printf("%d\n",result);
		return 0;
	}
	
	else if (*argv[2] == '/'){
		result = atoi(argv[1])/atoi(argv[3]);
		printf("%d\n",result);
		return 0;
	}
	return 0;
}
