#include "heap.h"

void heapSort(pointer arr, size_type size);

void testHeap() {
    // 初始化堆
    heap hp;
    heapInit(&hp);

    // 插入元素
    int values[] = {4, 10, 3, 5, 1, 8, 7, 6, 9, 2};
    size_type num_values = sizeof(values) / sizeof(values[0]);
    for (size_type i = 0; i < num_values; i++) {
        heapPush(&hp, values[i]);
    }

    // 打印堆中的元素
    printf("Heap elements: ");
    for (size_type i = 0; i < heapSize(&hp); i++) {
        printf("%d ", hp.data[i]);
    }
    printf("\n");

    // 获取堆顶元素
    val_type top_value = heapTop(&hp);
    printf("Heap Top: %d\n", top_value);

    // 堆排序
    heapSort(hp.data, heapSize(&hp));

    // 打印排序后的数组
    printf("Sorted Array: ");
    for (size_type i = 0; i < heapSize(&hp); i++) {
        printf("%d ", hp.data[i]);
    }
    printf("\n");

    // 销毁堆
    heapDestroy(&hp);
}

void printArray(pointer arr, size_type size) {
    for (size_type i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void testSort() {
    size_type size = 10;  // 数组大小
    int exampleArray[] = {4, 10, 3, 5, 1, 8, 7, 6, 9, 2};

    printf("Original Array: ");
    printArray(exampleArray, size);

    // 使用堆排序对数组进行排序
    heapSort(exampleArray, size);

    printf("Sorted Array: ");
    printArray(exampleArray, size);
}
