#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[10];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\n\nFirst Fit:\n");
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[10];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++){  
        int bestIdx = -1;  
        for (int j = 0; j < m; j++)  
        {  
            if (blockSize[j] >= processSize[i])  
            {  
                if (bestIdx == -1)  
                    bestIdx = j;  
                else if (blockSize[bestIdx] > blockSize[j])  
                    bestIdx = j;  
            }  
        }  
   
        if (bestIdx != -1){    
            allocation[i] = bestIdx;  
            blockSize[bestIdx] -= processSize[i];  
        }  
    }  
  
    printf("\n\nBest Fit: \n");
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blockSize[10], processSize[10];
    int m, n,c;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the sizes of the blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    printf("1.First Fit\n2.Best Fit\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    switch(c){
        case 1: firstFit(blockSize, m, processSize, n);
                break;
        case 2: bestFit(blockSize, m, processSize, n);
                break;
    }

    return 0;
}
