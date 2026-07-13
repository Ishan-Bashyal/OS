#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   pid_t pid;

   // Create child process
   pid = fork();

   if (pid < 0) {
       // Error occurred
       printf("Fork failed\n");
   }
   else if (pid == 0) {
       // Child process
       printf("Child Process: Running...\n");
       sleep(2);  // Simulate work
       printf("Child Process: Finished\n");
   }
   else {
       // Parent process
       printf("Parent Process: Waiting for child to finish...\n");
       wait(NULL);  // Parent waits here
       printf("Parent Process: Child finished, continuing...\n");
   }

   return 0;
}
