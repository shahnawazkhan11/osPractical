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