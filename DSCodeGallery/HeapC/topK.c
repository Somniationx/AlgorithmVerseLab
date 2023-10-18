#include <time.h>
#include "heap.h"

heap *createMinHeap(int capacity) {
    heap *minHeap = (heap *) (pointer) malloc(sizeof(heap));
    minHeap->data = (pointer) malloc(sizeof(val_type) * capacity);
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

const char *createFile(int itemNums) {
    const char *filename = "numbers.txt";
    int numIntegers = itemNums;

    // 打开文件以写入数据
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("无法打开文件");
        exit(-1);
    }

    // 使用当前时间作为随机种子
    unsigned int seed = (unsigned int) time(NULL);
    srand(seed);

    // 生成并写入整数
    for (int i = 0; i < numIntegers; i++) {
        int randomNumber = rand();
        fprintf(file, "%d\n", randomNumber);
    }

    // 关闭文件
    fclose(file);

    return filename;
}

void readAndMaintainMinHeap(const char *filename, int k, heap *minHeap) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("无法打开文件");
        exit(-1);
    }

    // 读取并插入前k个整数到最小堆中
    for (int i = 0; i < k; i++) {
        char line[100]; // 假设每行最多100个字符
        if (fgets(line, sizeof(line), file)) {
            int num = (int) strtol(line, NULL, 10);
            heapPush(minHeap, num);
        } else {
            break; // 文件已经结束
        }
    }

    // 继续读取文件中的其余整数并维护堆特性
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int num = (int) strtol(line, NULL, 10);
        if (num > heapTop(minHeap)) {
            // 如果新读取的数比堆顶元素大，弹出堆顶元素并插入新元素
            heapPop(minHeap);
            heapPush(minHeap, num);
        }
    }

    // 关闭文件
    fclose(file);
}

void printHeap(heap *minHeap) {
    for (size_type i = 0; i < heapSize(minHeap); i++) {
        printf("%d ", minHeap->data[i]);
    }
    printf("\n");
}

void testTopK() {
    int k = 10;
    const char *filename = createFile(100000);
    heap *minHeap = createMinHeap(k);

    readAndMaintainMinHeap(filename, k, minHeap);
    // 打印最小堆的内容
    printf("Elem of minHeap: ");
    printHeap(minHeap);
}




