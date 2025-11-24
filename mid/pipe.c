#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];              // fd[0] = read end, fd[1] = write end
    pid_t pid;
    char write_msg[100];
    char read_msg[100];

    // Create pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    // -------------------------------
    // Child Process
    // -------------------------------
    if (pid == 0) {
        close(fd[1]);   // Close write end (child only reads)

        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);

        close(fd[0]);
    }

    // -------------------------------
    // Parent Process
    // -------------------------------
    else {
        close(fd[0]);   // Close read end (parent only writes)

        printf("Enter message to send to child: ");
        fgets(write_msg, sizeof(write_msg), stdin);

        write(fd[1], write_msg, strlen(write_msg) + 1);

        close(fd[1]);
    }

    return 0;
}
