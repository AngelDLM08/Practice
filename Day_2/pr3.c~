#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 2

void *print_hello(void *num) {

	long t_num;
	t_num = (long) num;
	printf("Hello World! Thread num: %ld\n",t_num);
}

int main (int argc, char *argv[]) {

	int PEREMENNAYA = 10;
	printf("PEREMENNAYA= %d\n",PEREMENNAYA);
	pthread_t threads [NUM_THREADS];
	int rc;
	long t;
	int lol;
	for (t=0; t<NUM_THREADS; t++) {
		printf("In main: creating thread %ld\n",t);
		rc = pthread_create(&threads[t],NULL,print_hello, (void *)t);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit (-1);
		}
		
		for (lol=0; lol<10; lol++){
			if (t==0){PEREMENNAYA+=2; printf("Potok1, +2\n");}
				else {PEREMENNAYA-=2; printf("Potok2, -2\n");};
			printf("PEREMENNAYA= %d\n",PEREMENNAYA);
		}
	}

	for(t = 0; t< NUM_THREADS; t++) {
		pthread_join(threads[t], NULL);
		printf("Thread #%ld finished\n",t);
	}
	
	return 0;
}

