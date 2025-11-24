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
