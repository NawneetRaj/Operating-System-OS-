#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for(i = 1; i < n; ++i) {
        if(time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int findOptimal(int frames[], int pages[], int n, int index, int m) {
    int pos = -1, farthest = index;
    for(int i = 0; i < m; i++) {
        int j;
        for(j = index; j < n; j++) {
            if(frames[i] == pages[j]) {
                if(j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if(j == n) 
            return i;
    }
    return (pos == -1) ? 0 : pos;
}

void fifo(int pages[], int n, int frames[], int m) {
    int faults = 0, nextFrame = 0;
    printf("\nFIFO Page Replacement Algorithm\n");
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < m; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if(!found) { 
            frames[nextFrame] = pages[i];
            nextFrame = (nextFrame + 1) % m; 
            faults++;
        }
        printf("Page %d -> [", pages[i]);
        for(int j = 0; j < m; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf(" ");
        }
        printf("]\n");
    }
    printf("\nTotal Page Faults: %d\n", faults);
}

void lru(int pages[], int n, int frames[], int m) {
    int faults = 0, counter = 0, time[10];
    printf("\nLRU Page Replacement Algorithm\n");
    for(int i = 0; i < n; i++) {
        int flag1 = 0, flag2 = 0;
        for(int j = 0; j < m; j++) {
            if(frames[j] == pages[i]) { 
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        if(flag1 == 0) {
            for(int j = 0; j < m; j++) {
                if(frames[j] == -1) { 
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0) {
            int pos = findLRU(time, m);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        printf("Page %d -> [", pages[i]);
        for(int j = 0; j < m; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf(" ");
        }
        printf("]\n");
    }
    printf("\nTotal Page Faults: %d\n", faults);
}

void optimal(int pages[], int n, int frames[], int m) {
    int faults = 0;
    printf("\nOptimal Page Replacement Algorithm\n");
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < m; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            if(i < m) {
                frames[i] = pages[i]; 
            } else {
                int pos = findOptimal(frames, pages, n, i + 1, m);
                frames[pos] = pages[i]; 
            }
            faults++;
        }
        printf("Page %d -> [", pages[i]);
        for(int j = 0; j < m; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf(" ");
        }
        printf("]\n");
    }
    printf("\nTotal Page Faults: %d\n", faults);
}

int main() {
    int n, m, pages[30], frames[10];
    int choice;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        frames[i] = -1;
    }
    printf("\nSelect the Page Replacement Algorithm:\n");
    printf("1. FIFO\n2. LRU\n3. Optimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            fifo(pages, n, frames, m);
            break;
        case 2:
            lru(pages, n, frames, m);
            break;
        case 3:
            optimal(pages, n, frames, m);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}