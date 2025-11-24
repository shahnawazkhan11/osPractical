// mq_receiver.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    struct msg_buffer message;
    key_t key;
    int msgid;

    // Generate the same key
    key = ftok("progfile", 65);

    // Access message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Receive message of type 1
    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);

    printf("Received Message: %s\n", message.msg_text);

    // Remove the message queue (optional)
    // msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
