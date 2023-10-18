#include "heap.h"

void heapSort(pointer arr, size_type size) {

    // 向上建堆(O(NlogN))
//    for(int index = 1; index < size; ++index) {
//        adjust_up(arr, index);
//    }

    // 构建最大堆（向下建堆）(O(N))
    for (int index = (size - 1 - 1) / 2; index >= 0; index--) {
        adjust_down(arr, index, size);
    }

    // 排序
    for (int index = size - 1; index > 0; index--) {
        // 交换堆顶元素（最大值）与当前堆的最后一个元素
        swap(&arr[0], &arr[index]);

        // 减小堆的大小，排除最大值
        adjust_down(arr, 0, index);
    }
}







