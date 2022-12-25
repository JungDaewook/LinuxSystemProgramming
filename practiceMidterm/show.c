#include <stdio.h>
int main() {
	for (int i = 0; i<9; i++) {
		for (int j = 1; j <= 9-i; j++) {
			printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}
