#include <stdio.h>
#include <string.h>

main ()
{
	int i;
	double j;
	char *bug = NULL;

	for (i = 0; i < 5; i++) {
		j = i/2 + 1;
		printf("j is %lf \n", j);
	}
	
	//strcpy(bug, "hi");
	printf("bug is %s \n", bug);
}
