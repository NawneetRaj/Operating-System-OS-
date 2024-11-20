#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// FCFS algorithm
void fcfs(int tracks[], int n, int head) {
    int total_seek_time = 0;
    for (int i = 0; i < n; i++) {
        total_seek_time += abs(tracks[i] - head);
        head = tracks[i];
    }
    printf("FCFS Total Seek Time: %d\n", total_seek_time);
}

// SCAN algorithm
void scan(int tracks[], int n, int head, int disk_size) {
    int left[n], right[n], left_count = 0, right_count = 0;
    for (int i = 0; i < n; i++) {
        if (tracks[i] < head) left[left_count++] = tracks[i];
        else right[right_count++] = tracks[i];
    }
    qsort(left, left_count, sizeof(int), compare);
    qsort(right, right_count, sizeof(int), compare);

    int total_seek_time = 0;
    for (int i = 0; i < right_count; i++) {
        total_seek_time += abs(right[i] - head);
        head = right[i];
    }
    for (int i = left_count - 1; i >= 0; i--) {
        total_seek_time += abs(left[i] - head);
        head = left[i];
    }
    printf("SCAN Total Seek Time: %d\n", total_seek_time);
}

// C-SCAN algorithm
void c_scan(int tracks[], int n, int head, int disk_size) {
    int left[n], right[n], left_count = 0, right_count = 0;
    for (int i = 0; i < n; i++) {
        if (tracks[i] < head) left[left_count++] = tracks[i];
        else right[right_count++] = tracks[i];
    }
    qsort(left, left_count, sizeof(int), compare);
    qsort(right, right_count, sizeof(int), compare);

    int total_seek_time = 0;
    for (int i = 0; i < right_count; i++) {
        total_seek_time += abs(right[i] - head);
        head = right[i];
    }
    total_seek_time += abs(disk_size - head);
    head = 0;
    for (int i = 0; i < left_count; i++) {
        total_seek_time += abs(left[i] - head);
        head = left[i];
    }
    printf("C-SCAN Total Seek Time: %d\n", total_seek_time);
}

int main() {
    int n, head, disk_size;
    printf("Enter Number of Tracks: ");
    scanf("%d", &n);
    int tracks[n];
    printf("Enter Track Positions: ");
    for (int i = 0; i < n; i++) scanf("%d", &tracks[i]);
    printf("Enter Initial Head Position: ");
    scanf("%d", &head);
    printf("Enter Disk Size: ");
    scanf("%d", &disk_size);

    fcfs(tracks, n, head);
    scan(tracks, n, head, disk_size);
    c_scan(tracks, n, head, disk_size);

    return 0;
}
