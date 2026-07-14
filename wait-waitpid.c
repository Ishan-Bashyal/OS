#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();
        if (pid == 0) {
            printf("Child running...\n");
            sleep(2);
            _exit(0);
            } else {
                wait(NULL);
                printf("Child finished.\n");
            }
        return 0;
}
