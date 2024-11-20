#include <stdio.h>
#include <stdbool.h>

#define MAX_BLOCKS 100

int main() {
    int blocks[MAX_BLOCKS] = {0};
    int totalBlocks, startBlock, fileSize, i, j;

    printf("Enter the total number of blocks in memory: ");
    scanf("%d", &totalBlocks);

    if (totalBlocks > MAX_BLOCKS) {
        printf("Error: Maximum number of blocks is %d\n", MAX_BLOCKS);
        return 1;
    }

    while (true) {
        printf("\nEnter the starting block and size of the file: ");
        scanf("%d%d", &startBlock, &fileSize);

        if (startBlock < 0 || startBlock >= totalBlocks) {
            printf("Error: Starting block is out of range.\n");
            continue;
        }

        if (startBlock + fileSize > totalBlocks) {
            printf("Error: File size exceeds memory bounds.\n");
            continue;
        }

        bool canAllocate = true;
        for (i = startBlock; i < startBlock + fileSize; i++) {
            if (blocks[i] == 1) {
                canAllocate = false;
                break;
            }
        }

        if (!canAllocate) {
            printf("Error: Blocks already allocated.\n");
        } else {
            for (i = startBlock; i < startBlock + fileSize; i++) {
                blocks[i] = 1;
            }
            printf("File allocated successfully.\n");
        }

        printf("\nCurrent Memory Status (0: Free, 1: Allocated):\n");
        for (j = 0; j < totalBlocks; j++) {
            printf("%d ", blocks[j]);
        }

        char choice;
        printf("\n\nDo you want to allocate another file? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}
