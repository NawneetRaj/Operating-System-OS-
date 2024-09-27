#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;           // Process ID
    int arrival_time;   // Arrival Time
    int burst_time;     // Burst Time
    int waiting_time;   // Waiting Time
    int turnaround_time;// Turnaround Time
};

// Function to calculate waiting and turnaround times for FCFS
void FCFS(struct Process proc[], int n) {
    proc[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i-1].waiting_time + proc[i-1].burst_time;
    }
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
    printf("\nFCFS Scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

// Function to calculate waiting and turnaround times for SJF
void SJF(struct Process proc[], int n) {
    // Sort processes by burst time
    struct Process temp;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (proc[i].burst_time > proc[j].burst_time) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
    proc[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i-1].waiting_time + proc[i-1].burst_time;
    }
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
    printf("\nSJF Scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

// Function for Round Robin Scheduling
void RoundRobin(struct Process proc[], int n, int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = proc[i].burst_time;
    }

    int t = 0;
    printf("\nRound Robin Scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;

                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    proc[i].waiting_time = t - proc[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
        printf("P%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

// Driver function
int main() {
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
    }

    printf("\nChoose a scheduling algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FCFS(proc, n);
            break;
        case 2:
            SJF(proc, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            RoundRobin(proc, n, quantum);
            break;
        default:
            printf("Invalid choice! Please select a valid scheduling algorithm.\n");
            break;
    }

    return 0;
}
