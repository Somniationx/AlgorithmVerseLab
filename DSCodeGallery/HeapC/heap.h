#ifndef HEAP_C_HEAP_H
#define HEAP_C_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int val_type;     // 数据类型
typedef int *pointer;     // 指针类型
typedef int size_type; // 大小类型

// 堆的数据结构定义
struct heap {
    pointer data;       // 存储元素的数组
    size_type size;     // 堆中的元素数量
    size_type capacity; // 堆的容量
};

typedef struct heap heap;

// 初始化堆
void heapInit(heap *hp);

// 清空堆（释放内存并重置属性）
void heapClear(heap *hp);

// 销毁堆（清空堆并销毁堆结构）
void heapDestroy(heap *hp);

// 交换两个元素的值
void swap(pointer val1, pointer val2);

// 获取堆的元素数量
size_type heapSize(heap *hp);

// 将新元素上浮以维持最大堆性质
void adjust_up(pointer data, size_type index);

// 将元素下沉以维持最大堆性质
void adjust_down(pointer data, size_type parent, size_type size);

// 将元素推入堆
void heapPush(heap *hp, val_type val);

// 检查堆是否为空
bool heapEmpty(heap *hp);

// 弹出堆顶元素
void heapPop(heap *hp);

// 获取堆顶元素的值
val_type heapTop(heap *hp);

#endif // HEAP_C_HEAP_H
