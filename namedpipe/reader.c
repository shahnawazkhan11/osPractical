// mkfifo_receiver.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    // Create FIFO using mkfifo()
    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo");
    }

    int fd;
    char buffer[100];

    fd = open("myfifo", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    read(fd, buffer, sizeof(buffer));

    printf("Received Message using mkfifo: %s\n", buffer);

    close(fd);
    return 0;
}
