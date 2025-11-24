// reader.c
#include <stdio.h>
#include <stdlib.h>
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
    struct msg_buffer message;

    // Key for shared memory
    key1 = ftok("shmfile", 65);

    // Access shared memory
    shmid = shmget(key1, 1024, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    shared_data = (char *) shmat(shmid, NULL, 0);

    // Message queue key
    key2 = ftok("msgfile", 75);

    // Access message queue
    msgid = msgget(key2, 0666 | IPC_CREAT);

    printf("Reader waiting for signal...\n");

    // Receive message/signal
    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);

    printf("Signal received from writer!\n");
    printf("Reading shared memory...\n\n");

    // Print shared memory contents
    printf("Data from shared memory: %s\n", shared_data);

    // Detach shared memory
    shmdt(shared_data);

    // Remove shared memory + message queue (optional)
    // shmctl(shmid, IPC_RMID, NULL);
    // msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
