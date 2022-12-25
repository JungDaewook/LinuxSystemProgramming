#include <stdio.h>
#include <pthread.h>

void doSum(int *sum) {
    for (int i = sum[0]; i <= sum[1]; i++){
        *(sum+2) += i;
    }
}

int main() {
    pthread_t tid1, tid2;
    static int sum1[3] = {1,50,0};
    static int sum2[3] = {51,100,0};
    int totalSum;
    
    //create thread with tid1 and execute doSum(sum1)
    if (pthread_create(&tid1, NULL, (void *)doSum, (void *)sum1) < 0)  {
		perror("pthread_create");
		exit(1);
	}

    //create thread with tid1 and execute doSum(sum2)
    if (pthread_create(&tid2, NULL, (void *)doSum, (void *)sum2) < 0)  {
		perror("pthread_create");
		exit(1);
	}

    //wait(join) until tid1 thread get killed 
    if (pthread_join(tid1, NULL) < 0)  {
		perror("pthread_join");
		exit(1);
	}

    //wait(join) until tid2 thread get killed 
	if (pthread_join(tid2, NULL) < 0)  {
		perror("pthread_join");
		exit(1);
	}

    totalSum = *(sum1+2) + *(sum2+2);
    printf("Sum from 1 to 100 : %d\n", totalSum);
    return 0;
}
