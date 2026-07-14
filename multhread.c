
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

// THREAD 1: Print System Information
void *systemInfo(void *arg) {
    struct utsname sysInfo;
    uname(&sysInfo);

    printf("[System Info Thread] OS: %s, Version: %s\n", sysInfo.sysname, sysInfo.version);
    pthread_exit(NULL);
}

// THREAD 2: Simulate Disk I/O
void *diskIO(void *arg) {
    printf("[Disk I/O Thread]    Starting disk read operation...\n");
    sleep(2); // Wait for 2 seconds (simulating a slow disk read operation).
    printf("[Disk I/O Thread]    Disk read completed!\n");
    pthread_exit(NULL);
}

// THREAD 3: Simulate Network Activity
void *networkActivity(void *arg) {
    printf("[Network Thread]     Sending data over the network...\n");
    sleep(1); // Simulate a 1-second network delay.
    printf("[Network Thread]     Data sent successfully!\n");
    pthread_exit(NULL);
}

// THREAD 4: Simulate File System Operations
void *fileSystem(void *arg) {
    printf("[File System Thread] Opening file 'log.txt'...\n");
    sleep(1);

    FILE *fp = fopen("log.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "OS Service Log: File system thread executed successfully.\n");
        fclose(fp);
        printf("[File System Thread] Data written to 'log.txt' and file closed.\n");
    } else {
        printf("[File System Thread] ERROR: Could not open file for writing.\n");
    }
    pthread_exit(NULL);
}

// THREAD 5: Simulate Print Spooler Service
void *printSpooler(void *arg) {
    printf("[Print Spooler Thread] Print job received. Adding to spooler queue...\n");
    sleep(2);
    printf("[Print Spooler Thread] Sending document to printer...\n");
    sleep(1);
    printf("[Print Spooler Thread] Print job completed successfully!\n");
    pthread_exit(NULL);
}

// MAIN: Create and Manage All 5 Threads
int main() {
    pthread_t thread1, thread2, thread3, thread4, thread5;

    printf("OS Services Simulation: \n");
    printf("Main Process ID: %d\n\n", getpid());

    pthread_create(&thread1, NULL, systemInfo,      NULL);
    pthread_create(&thread2, NULL, diskIO,          NULL);
    pthread_create(&thread3, NULL, networkActivity, NULL);
    pthread_create(&thread4, NULL, fileSystem,      NULL);
    pthread_create(&thread5, NULL, printSpooler,    NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    printf("\nAll OS service threads completed. Main process exiting.\n");

    return 0;
}
