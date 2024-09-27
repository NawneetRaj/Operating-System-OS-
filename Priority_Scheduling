#include <stdio.h>

struct Process {
    int pid;            
    int arrival_time;    
    int burst_time;      
    int priority;        
    int waiting_time;    
    int turnaround_time; 
    int completion_time; 
};

void sort_by_arrival_and_priority(struct Process proc[], int n) {
    struct Process temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].arrival_time > proc[j].arrival_time || 
               (proc[i].arrival_time == proc[j].arrival_time && proc[i].priority > proc[j].priority)) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void calculate_times(struct Process proc[], int n) {
    int current_time = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < proc[i].arrival_time) {
            current_time = proc[i].arrival_time;
        }
        proc[i].completion_time = current_time + proc[i].burst_time;
        proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;

        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;

        current_time += proc[i].burst_time;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time, proc[i].burst_time, 
               proc[i].priority, proc[i].completion_time, proc[i].turnaround_time, proc[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].arrival_time, &proc[i].burst_time, &proc[i].priority);
    }

    sort_by_arrival_and_priority(proc, n);
    calculate_times(proc, n);

    return 0;
}
