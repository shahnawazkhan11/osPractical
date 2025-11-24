#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid = fork();

    // Fork returns a positive PID in the parent process
    if (child_pid > 0) {
        // --- Parent Process ---
        printf("PARENT: My PID is %d\n", getpid());
        printf("PARENT: My child's PID is %d\n", child_pid);
        
     
        printf("PARENT: I am sleeping for 30 seconds...\n");
        sleep(30);
        
 
        wait(NULL);
        printf("PARENT: I have reaped the child. I will now exit.\n");
    }
    // Fork returns 0 in the child process
    else if (child_pid == 0) {
        // --- Child Process ---
        printf("CHILD: I am running, my PID is %d\n", getpid());
        printf("CHILD: I am finished and will now exit.\n");
        
        // The child exits immediately, becoming a zombie.
        exit(0);
    }
    // Fork returns -1 if it fails
    else {
        perror("fork error");
        return 1;
    }

    return 0;
}