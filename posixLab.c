#include <pthread.h>
#include <stdio.h>
#include <unistd.h>     // for sleep()
#include <sys/utsname.h> // for uname()

void *systemInfo(void *arg) { // This is the function that the system information thread will run.
    struct utsname sysInfo;   // Create a structure to hold system information.
    uname(&sysInfo);          // Fill the structure with the current operating system's name, version, etc.
    
    printf("[System Info Thread] OS: %s, Version: %s\n", sysInfo.sysname, sysInfo.version);
    pthread_exit(NULL);
}

// Simulates a disk read operation.
void *diskIO(void *arg) {
    printf("[Disk I/O Thread] Starting disk read operation...\n");
    sleep(2); // Wait for 2 seconds (simulating slow disk operation).
    printf("[Disk I/O Thread] Disk read completed!\n");
    pthread_exit(NULL);
}

// Simulates sending data over a network.
void *networkActivity(void *arg) {
    printf("[Network Thread] Sending data over the network...\n");
    sleep(1); // Simulate 1-second network delay.
    printf("[Network Thread] Data sent successfully!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2, thread3; // pthread_t is a data type for thread IDs.
    
    printf("Main Process ID: %d\n", getpid());
    
    // Create three threads
    pthread_create(&thread1, NULL, systemInfo, NULL);
    pthread_create(&thread2, NULL, diskIO, NULL);
    pthread_create(&thread3, NULL, networkActivity, NULL);
    /*
    &thread* - Where to store the new thread ID.
    NULL - Use default thread attributes.
    systemInfo - Name of the function the thread will execute.
    NULL - No arguments passed to the thread function.
    */
    
    // Wait for all threads to finish
    pthread_join(thread1, NULL); // pthread_join() waits for a thread to finish execution.
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    
    printf("All OS tasks (threads) completed. Main process exiting.\n");
    
    return 0;
}
