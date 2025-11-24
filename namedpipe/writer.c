// mkfifo_sender.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    // Create FIFO using mkfifo()
    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo");
    }

    int fd;
    char message[100];
    int size;

    fd = open("myfifo", O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    printf("Enter size of message: ");
    scanf("%d", &size);
    getchar();

    if (size > 99) size = 99;

    printf("Enter message: ");
    fgets(message, size + 1, stdin);

    write(fd, message, strlen(message) + 1);

    printf("Message sent using mkfifo!\n");

    close(fd);
    return 0;
}
