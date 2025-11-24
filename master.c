//////////////////////////////////// FCFS ///////////////////////////////////////////////////////
/*

    #include <stdio.h>

struct Process {
    int pid;   // Process ID
    int bt;    // Burst time
    int at;    // Arrival time
    int wt;    // Waiting time
    int tat;   // Turnaround time
    int rt;    // Response time
    int st;    // Start time
    int et;    // End time
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        p[i].pid = i + 1;
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
    }

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at)
                swap(&p[j], &p[j + 1]);
        }
    }

    // First process calculations
    p[0].st = p[0].at;
    p[0].et = p[0].st + p[0].bt;
    p[0].rt = p[0].st - p[0].at;
    p[0].wt = p[0].et - p[0].at - p[0].bt;
    p[0].tat = p[0].et - p[0].at;

    // For subsequent processes
    for (int i = 1; i < n; i++) {
        // Start time is previous process’s end time
        if (p[i-1].et < p[i].at)
            p[i].st = p[i].at;  // CPU idle until this process arrives
        else
            p[i].st = p[i-1].et;

        p[i].et = p[i].st + p[i].bt;
        p[i].rt = p[i].st - p[i].at;
        p[i].wt = p[i].et - p[i].at - p[i].bt;
        p[i].tat = p[i].et - p[i].at;
    }

    float total_wt = 0, total_tat = 0;

    printf("\n-----------------------------------------------------------\n");
    printf("PID\tAT\tBT\tST\tET\tWT\tTAT\tRT\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].et, p[i].wt, p[i].tat, p[i].rt);
    }

    printf("-----------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}


*/


//////////////////////////   SJFS /////////////////////////

/*
#include <stdio.h>

struct Process
{
    int pid; // Process ID
    int bt;  // Burst time
    int at;  // Arrival time
    int wt;  // Waiting time
    int tat; // Turnaround time
    int rt;  // Response time
    int st;  // Start time
    int et;  // End time
};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for (int i = 0; i < n; i++)
    {
        printf("\nProcess %d:\n", i + 1);
        p[i].pid = i + 1;
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
    }

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].bt > p[j + 1].bt ||
                (p[j].bt == p[j + 1].bt && p[j].at > p[j + 1].at))
                swap(&p[j], &p[j + 1]);
        }
    }

    // First process calculations
    p[0].st = p[0].at;
    p[0].et = p[0].st + p[0].bt;
    p[0].rt = p[0].st - p[0].at;
    p[0].wt = p[0].et - p[0].at - p[0].bt;
    p[0].tat = p[0].et - p[0].at;

    // For subsequent processes
    for (int i = 1; i < n; i++)
    {
        // Start time is previous process’s end time
        if (p[i - 1].et < p[i].at)
            p[i].st = p[i].at; // CPU idle until this process arrives
        else
            p[i].st = p[i - 1].et;

        p[i].et = p[i].st + p[i].bt;
        p[i].rt = p[i].st - p[i].at;
        p[i].wt = p[i].et - p[i].at - p[i].bt;
        p[i].tat = p[i].et - p[i].at;
    }

    float total_wt = 0, total_tat = 0;

    printf("\n-----------------------------------------------------------\n");
    printf("PID\tAT\tBT\tST\tET\tWT\tTAT\tRT\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        total_wt += p[i].wt;
        total_tat += p[i].tat;

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].et, p[i].wt, p[i].tat, p[i].rt);
    }

    printf("-----------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}

*/


//////////////////////////////PRIORITY //////////////////////////////

/*

#include <stdio.h>

struct Process
{
    int pid; // Process ID
    int bt;  // Burst time
    int at;  // Arrival time
    int pr;  // Priority (lower number = higher priority)
    int wt;  // Waiting time
    int tat; // Turnaround time
    int rt;  // Response time
    int st;  // Start time
    int et;  // End time
};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for (int i = 0; i < n; i++)
    {
        printf("\nProcess %d:\n", i + 1);
        p[i].pid = i + 1;

        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);

        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);

        printf("Enter priority (lower number = higher priority): ");
        scanf("%d", &p[i].pr);
    }

    // Sort by priority (if tie, then by arrival time)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].pr > p[j + 1].pr ||
                (p[j].pr == p[j + 1].pr && p[j].at > p[j + 1].at))
                swap(&p[j], &p[j + 1]);
        }
    }

    // First process calculations
    p[0].st = p[0].at;
    p[0].et = p[0].st + p[0].bt;
    p[0].rt = p[0].st - p[0].at;
    p[0].wt = p[0].et - p[0].at - p[0].bt;
    p[0].tat = p[0].et - p[0].at;

    // For subsequent processes
    for (int i = 1; i < n; i++)
    {
        // Start time is previous process’s end time
        if (p[i - 1].et < p[i].at)
            p[i].st = p[i].at; // CPU idle until this process arrives
        else
            p[i].st = p[i - 1].et;

        p[i].et = p[i].st + p[i].bt;
        p[i].rt = p[i].st - p[i].at;
        p[i].wt = p[i].et - p[i].at - p[i].bt;
        p[i].tat = p[i].et - p[i].at;
    }

    float total_wt = 0, total_tat = 0;

    printf("\n-------------------------------------------------------------------\n");
    printf("PID\tAT\tBT\tPR\tST\tET\tWT\tTAT\tRT\n");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        total_wt += p[i].wt;
        total_tat += p[i].tat;

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].pr, p[i].st, p[i].et, p[i].wt, p[i].tat, p[i].rt);
    }

    printf("-------------------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}

*/


////////////////////////////  ROUND ROBIN //////////////////////////

/*
#include <stdio.h>

struct Process
{
    int pid;             // Process ID
    int burst_time;      // Original burst time
    int waiting_time;    // Waiting time
    int turnaround_time; // Turnaround time

};

void roundRobinScheduling(struct Process processes[], int n, int time_quantum)
{
    printf("\n=== ROUND ROBIN SCHEDULING ===\n");
    printf("Time Quantum: %d\n\n", time_quantum);

    int rembt[n]; // Remaining burst time array
    int current_time = 0;
    int completed = 0;
    int i = 0;

    // Initialize remaining burst time array
    for (int j = 0; j < n; j++)
    {
        rembt[j] = processes[j].burst_time;
    }

    // Continue until all processes are completed
    while (completed < n)
    {
        if (rembt[i] > 0)
        {
            if (rembt[i] > time_quantum)
            {
                // Process needs more time than quantum
                current_time += time_quantum;
                rembt[i] -= time_quantum;
            }
            else
            {
                // Process can complete within quantum
                current_time += rembt[i];
                rembt[i] = 0;

                // Process completed
                completed++;
                processes[i].turnaround_time = current_time; // TAT = completion time since arrival time = 0
                processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
            }
        }

        // Move to next process (circular)
        i = (i + 1) % n;
    }
}

void displayResults(struct Process processes[], int n)
{
    printf("\nProcess ID\tBT\tWT\tTAT\n");
    printf("----------\t--\t--\t---\n");

    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t%d\n",
               processes[i].pid,
               processes[i].burst_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);

        total_wt += processes[i].waiting_time;
        total_tat += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main()
{
    int n, time_quantum;

    printf("Round Robin Scheduling Algorithm\n");
    printf("================================\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++)
    {
        printf("\nProcess %d:\n", i + 1);
        processes[i].pid = i + 1;

        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);

        // Initialize values
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;

    }

    // Execute Round Robin scheduling
    roundRobinScheduling(processes, n, time_quantum);
    displayResults(processes, n);

    return 0;
}
*/

//////////////////// ORPHAN ///////////////////////

/*

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

*/

////////////////////////////// ZOMBIE ///////////////////

/*

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

*/



//////////////////////////// FORKTREE /////////////////

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
    int pid1 , pid2;
    int pid1_child;
    printf("root process started with pid = %d \n" , getpid());
    pid1 = fork();
    if(pid1 <0 )
    {
        printf("error");
    }
    else if(pid1==0)
    {
        printf("CHILD 1 : parent process id %d , process id %d \n",getppid(),getpid());

        pid1_child = fork();
        if(pid1_child == 0)
        {
            printf("GRAND CHILD (child of 1) : parent pid %d , process id %d \n",getppid() , getpid());

        }
        else
        {
            wait(NULL);
        }
      
    }
    else
    {
        pid2 = fork();
        if(pid2 < 0)
        {
            printf("error");
            return 1;
        }
        else if(pid2 == 0)
        {
            printf("CHILD 2 : parent process id %d , process id %d \n",getppid(),getpid());

            
        }
        else
        {
            wait(NULL);
            wait(NULL);
        }
    }
}

*/


///////////////////////////  PIPE ////////////////////

/*


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd[2];  // fd[0] for reading, fd[1] for writing
    pid_t pid;
    char message[] = "Hello from Child!";
    char buffer[50];

    // Create pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        close(fd[0]);  // Close unused read end
        write(fd[1], message, strlen(message) + 1);  // Write to pipe
        close(fd[1]);  // Close write end after writing
    } else {
        // Parent process
        close(fd[1]);  // Close unused write end
        read(fd[0], buffer, sizeof(buffer));  // Read from pipe
        printf("Parent received: %s\n", buffer);
        close(fd[0]);  // Close read end after reading
    }

    return 0;
}

*/

//////////////////////////////////////////////////// NAMED PIPE ////////////////////////////////////////////////////////////

//////SENDER///

/*
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
*/

////RECIEVER////

/*
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

*/


////////////////////////////////////////////////////// MESSAGE QUEUE /////////////////////////////////////////////////////////

///SENDER///
/*
// mq_sender.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer
{
    long msg_type;
    char msg_text[100];
};

int main()  
{
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

*/

/// RECIEVER ///
/*
// mq_receiver.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer
{
    long msg_type;
    char msg_text[100];
};

int main()
{
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

*/

///////////////////////////  SHARED MEMORY ////////////////
///SENDER///
/*
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

*/

/// RECIEVER ///
/*
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

*/


///////////////////////////////////////  PAGE  REPLACEMENT //////////////////////////////////

/////// FIFO ///////
/*
#include <stdio.h>

int main()
{
    int pages, frames;

    // Input: number of pages
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    char ref[100]; // reference string
    printf("Enter the page reference string (no spaces): ");
    scanf("%s", ref);

    // Input: number of frames
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[10];
    int i, j, k = 0;
    int faults = 0;
    int found;

    // initialize frame array with -1 (empty)
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");
    printf("------------------------\n");

    // FIFO Algorithm
    for (i = 0; i < pages; i++)
    {

        found = 0;

        // check if page already exists in frame
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == ref[i])
            {
                found = 1;
                break;
            }
        }

        // if not found → page fault
        if (!found)
        {
            frame[k] = ref[i]; // replace oldest (k pointer)
            k = (k + 1) % frames;
            faults++;
        }

        // print the frames after each step
        printf("%c\t", ref[i]);
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%c ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}

*/

/////// LRU ///////
/*
#include <stdio.h>

int main()
{
    int pages, frames;

    // Input: number of pages
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    char ref[100]; // reference string
    printf("Enter the page reference string (no spaces): ");
    scanf("%s", ref);

    // Input: number of frames
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[10];
    int i, j, k;
    int faults = 0;
    int found;

    // initialize frames
    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");
    printf("------------------------\n");

    // LRU Algorithm
    for (i = 0; i < pages; i++)
    {
        found = 0;

        // Check if page already present in frame
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == ref[i])
            {
                found = 1;
                break;
            }
        }

        // If page not found → Page Fault → Apply LRU
        if (!found)
        {
            // find LRU page (the one used farthest in past)
            int lru_index = 0;
            int farthest = 9999;

            for (j = 0; j < frames; j++)
            {
                if (frame[j] == -1)
                {
                    lru_index = j;
                    break;
                }

                // Check last use of frame[j]
                int last_use = -1;
                for (k = i - 1; k >= 0; k--)
                {
                    if (ref[k] == frame[j])
                    {
                        last_use = k;
                        break;
                    }
                }

                // If this page was least recently used
                if (last_use < farthest)
                {
                    farthest = last_use;
                    lru_index = j;
                }
            }

            // Replace LRU page
            frame[lru_index] = ref[i];
            faults++;
        }

        // Print frames
        printf("%c\t", ref[i]);
        for (j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%c ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}

*/

/////// OPTIMAL ////
/*
#include <stdio.h>

int main()
{
    int pages, frames;
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    char ref[100];
    printf("Enter the page reference string (no spaces): ");
    scanf("%s", ref);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[10], faults = 0;
    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n-------------------------\n");

    for (int i = 0; i < pages; i++)
    {
        int found = 0;

        // Check if page exists
        for (int j = 0; j < frames; j++)
            if (frame[j] == ref[i])
            {
                found = 1;
                break;
            }

        if (!found)
        {
            int optimal = -1, far = -1;

            // Check for empty frame first
            for (int j = 0; j < frames; j++)
                if (frame[j] == -1)
                {
                    optimal = j;
                    break;
                }

            // No empty frame → find optimal
            if (optimal == -1)
            {
                for (int j = 0; j < frames; j++)
                {
                    int k;
                    for (k = i + 1; k < pages; k++)
                        if (ref[k] == frame[j])
                            break;

                    if (k == pages)
                    {
                        optimal = j;
                        break;
                    } // never used again
                    if (k > far)
                    {
                        far = k;
                        optimal = j;
                    } // farthest future use
                }
            }

            frame[optimal] = ref[i];
            faults++;
        }

        // Print frames
        printf("%c\t", ref[i]);
        for (int j = 0; j < frames; j++)
            printf("%c ", frame[j] == -1 ? '-' : frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
*/