#include <stdio.h>
#include <pthread.h>

void *myThread(void *arg) {
	printf("Thread is running!\n");
	return NULL;
}

int main() {
	pthread_t thread;
	printf("Thread object created (New State)\n");
	pthread_create(&thread, NULL, myThread, NULL);
	pthread_join(thread, NULL); 
	return 0;
}
