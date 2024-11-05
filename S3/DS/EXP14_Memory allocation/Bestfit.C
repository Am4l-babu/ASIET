#include <stdio.h>

typedef struct {
    int size;
    int isFree;
} MemoryBlock;

int bestFit(MemoryBlock blocks[], int numBlocks, int processSize) {
    int bestIndex = -1;
    int minSize = 999999;

    for (int i = 0; i < numBlocks; i++) {
        if (blocks[i].isFree && blocks[i].size >= processSize) {
            if (blocks[i].size < minSize) {
                minSize = blocks[i].size;
                bestIndex = i;
            }
        }
    }

    if (bestIndex != -1) {
        blocks[bestIndex].isFree = 0;
        printf("Process of size %d allocated in block of size %d\n", processSize, blocks[bestIndex].size);
        return bestIndex;
    } else {
        printf("No suitable block found for process of size %d\n", processSize);
        return -1;
    }
}

int main() {
    MemoryBlock blocks[100];
    int numBlocks;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    for (int i = 0; i < numBlocks; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &blocks[i].size);
        blocks[i].isFree = 1;
    }

    int processSize;
    while (1) {
        printf("\nEnter the size of the process to allocate (0 to exit): ");
        scanf("%d", &processSize);
        if (processSize == 0) {
            break;
        }
        bestFit(blocks, numBlocks, processSize);
    }

    printf("\nRemaining memory blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d: Size = %d, Status = %s\n", i + 1, blocks[i].size, blocks[i].isFree ? "Free" : "Allocated");
    }

    return 0;
}
