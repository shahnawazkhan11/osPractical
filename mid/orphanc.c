#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h> // For exit()

int main()
{
    pid_t pid = fork(); // Use pid_t for process IDs

    if (pid > 0)
    {
        // PARENT PROCESS
        printf("PARENT: My PID is %d, my child's PID is %d. I am now exiting.\n", getpid(), pid);
       
    }
    else if (pid == 0)
    {
        // CHILD PROCESS
        sleep(2);
        printf("CHILD: My PID is %d, my new parent's PID is %d. I was an orphan!\n", getpid(), getppid());
        exit(0); // Child exits
    }
    else
    {
        // FORK FAILED
        perror("fork error");
        return 1;
    }

    // The parent exits here by returning
    return 0;
}