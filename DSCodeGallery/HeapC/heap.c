#include "heap.h"

// 初始化堆
void heapInit(heap *hp) {
    hp->data = NULL;  // 初始化数据指针为空
    hp->size = 0;     // 初始化堆中元素数量为0
    hp->capacity = 0; // 初始化堆的容量为0
}

// 清空堆（释放内存并重置属性）
void heapClear(heap *hp) {
    if (hp->data) {
        free(hp->data); // 释放堆的数据数组内存
        hp->data = NULL; // 将数据指针重置为空
        hp->size = 0;    // 重置堆中元素数量为0
        hp->capacity = 0; // 重置堆的容量为0
    }
}

// 销毁堆（清空堆并销毁堆结构）
void heapDestroy(heap *hp) {
    heapClear(hp); // 调用清空函数来释放内存并重置属性
}

// 交换两个元素的值
void swap(pointer val1, pointer val2) {
    val_type tmp = *val1; // 交换两个元素的值
    *val1 = *val2;
    *val2 = tmp;
}

// 获取堆的元素数量
size_type heapSize(heap *hp) {
    return hp->size; // 返回堆中的元素数量
}

// 将新元素上浮以维持最大堆性质
void adjust_up(pointer data, size_type index) {
    size_type child = index;
    size_type parent;
    while (child > 0) {
        parent = (child - 1) / 2; // 计算父节点的索引
        if (data[child] > data[parent]) { // 如果子节点大于父节点
            swap(&data[child], &data[parent]); // 交换它们
            child = parent; // 继续检查上一级父节点
        }
        else {
            break; // 最大堆性质已满足，退出循环
        }
    }
}

// 将元素下沉以维持最大堆性质
void adjust_down(pointer data, size_type parent, size_type size) {
    size_type biggest = parent;
    while (parent < size) {
        size_type leftChild = parent * 2 + 1; // 计算左子节点索引
        size_type rightChild = leftChild + 1; // 计算右子节点索引

        if (leftChild < size && data[leftChild] > data[biggest]) {
            biggest = leftChild; // 找到左子节点比父节点大的情况
        }

        if (rightChild < size && data[rightChild] > data[biggest]) {
            biggest = rightChild; // 找到右子节点比父节点大的情况
        }

        if (biggest != parent) {
            swap(&data[biggest], &data[parent]); // 交换父节点和子节点
            parent = biggest; // 继续检查下一级子节点
        } else {
            break; // 最大堆性质已满足，退出循环
        }
    }
}

// 将元素推入堆
void heapPush(heap *hp, val_type val) {
    assert(hp); // 检查堆是否有效
    if (hp->size == hp->capacity) {
        size_type new_capacity = (hp->capacity == 0) ? 4 : hp->capacity * 2; // 计算新容量

        pointer tmp = (pointer)malloc(sizeof(val_type) * new_capacity); // 分配新内存
        if (!tmp) {
            perror("Malloc fail in heapPush function!\n"); // 处理内存分配失败情况
            exit(-1); // 退出程序
        }

        if (hp->data) {
            for (size_type index = 0; index < hp->size; ++index) {
                tmp[index] = hp->data[index]; // 复制数据到新内存
            }
            free(hp->data); // 释放旧内存
        }

        hp->data = tmp; // 更新数据指针
        hp->capacity = new_capacity; // 更新容量
    }

    hp->data[hp->size++] = val; // 将新元素添加到堆
    adjust_up(hp->data, hp->size - 1); // 调整堆以维持性质
}

// 检查堆是否为空
bool heapEmpty(heap *hp) {
    assert(hp); // 检查堆是否有效
    return hp->size == 0; // 返回是否堆为空
}

// 弹出堆顶元素
void heapPop(heap *hp) {
    assert(hp); // 检查堆是否有效
    if (!heapEmpty(hp)) {
        swap(&hp->data[0], &hp->data[hp->size - 1]); // 交换堆顶元素和最后一个元素
        --hp->size; // 减少元素数量
        adjust_down(hp->data, 0, hp->size); // 调整堆以维持性质
    }
}

// 获取堆顶元素的值
val_type heapTop(heap *hp) {
    assert(hp); // 检查堆是否有效
    if (!heapEmpty(hp)) {
        return hp->data[0]; // 返回堆顶元素的值
    }
    else {
        perror("heapTop: Heap is empty!\n"); // 处理堆为空的情况
        exit(-1); // 退出程序
    }
}
