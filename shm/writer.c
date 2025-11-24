// writer.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[10];
};

int main() {
    key_t key1, key2;
    int shmid, msgid;
    char *shared_data;
    char input[100];
    struct msg_buffer message;

    // Key for shared memory
    key1 = ftok("shmfile", 65);

    // Create shared memory segment
    shmid = shmget(key1, 1024, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    shared_data = (char *) shmat(shmid, NULL, 0);

    printf("Enter data to write into shared memory: ");
    fgets(input, sizeof(input), stdin);
    strcpy(shared_data, input);

    printf("Data written to shared memory: %s\n", shared_data);

    // Message queue key
    key2 = ftok("msgfile", 75);

    // Create message queue
    msgid = msgget(key2, 0666 | IPC_CREAT);

    // Send signal/message
    message.msg_type = 1;
    strcpy(message.msg_text, "done");

    msgsnd(msgid, &message, sizeof(message.msg_text), 0);

    printf("Signal sent to reader through message queue.\n");

    // Detach shared memory
    shmdt(shared_data);

    return 0;
}
