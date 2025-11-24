// mq_sender.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // Generate unique key
    key = ftok("progfile", 65);

    // Create message queue and return id
    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Enter message to send: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);

    message.msg_type = 1; // message type must be > 0

    // Send message
    msgsnd(msgid, &message, sizeof(message.msg_text), 0);

    printf("Message sent: %s\n", message.msg_text);

    return 0;
}
