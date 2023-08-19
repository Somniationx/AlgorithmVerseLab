#include "SeqList.h"

void SeqListInit(SeqList *seqList) {
    //断言 顺序表指针不为空
    assert(seqList);

    //初始时数据个数、容量均为0，指针为空指针
    seqList->size = 0;
    seqList->capacity = 0;
    seqList->data = NULL;
}

void CheckCapacity(SeqList *seqList) {
    assert(seqList);
    //数据个数与容量相等则进行扩容
    if (seqList->size == seqList->capacity) {
        //将要扩容的容量大小
        size_t newCapacity = (seqList->capacity == 0) ? 4 : seqList->capacity * 2;

        //开辟空间
        SLDataType *temp = (SLDataType *) malloc(sizeof(SLDataType) * newCapacity);

        //判断空间是否开辟成功
        if (temp) {
            //成功开辟空间先进行数据移动
            for (size_t index = 0; index < seqList->size; index++) {
                temp[index] = seqList->data[index];
            }
            //非空就释放空间
            if (!seqList->data) free(seqList->data);
            seqList->data = temp;
            seqList->capacity = newCapacity;
        } else {
            // 分配内存失败，释放旧的数据数组并直接结束程序
            if (!seqList->data) free(seqList->data);
            seqList->data = NULL;
            seqList->capacity = 0;

            fprintf(stderr, "扩容失败！\n");
            exit(-1); // 直接结束程序
        }
    }
}

bool Empty(SeqList *seqList) {
    return (seqList->size == 0);
}

void SeqListPushBack(SeqList *seqList, SLDataType value) {
    assert(seqList);

    //插入数据先检查容量!
    CheckCapacity(seqList);

    //插入数据 不要忘记增加size
    seqList->data[seqList->size++] = value;
}

void SeqListPopBack(SeqList *seqList) {
    assert(seqList);
    //顺序表不能为空
    assert(!Empty(seqList));

    //size--即可实现删除
    seqList->size--;
}

void SeqListPushFront(SeqList *seqList, SLDataType value) {
    assert(seqList);

    CheckCapacity(seqList);

    //头部插入数据要先将所有数据向后移动
    for (size_t index = seqList->size; index > 0; index--) {
        seqList->data[index] = seqList->data[index - 1];
    }
    //移动后插入数据
    seqList->data[0] = value;

    //插入后和更新size
    seqList->size++;
}

void SeqListPopFront(SeqList *seqList) {
    assert(seqList);
    assert(!Empty(seqList));

    //头部删除数据也需要移动数据
    for (size_t index = 0; index < seqList->size - 1; index++) {
        seqList->data[index] = seqList->data[index + 1];
    }

    //更新size
    seqList->size--;
}

size_t SeqListFind(SeqList *seqList, SLDataType value) {
    for (size_t index = 0; index < seqList->size; index++) {
        if (seqList->data[index] == value) {
            return index; // 找到值后返回其索引
        }
    }
    return (size_t) -1; // 如果值未找到，则返回 size_t 类型的最大值
}

void SeqListInsert(SeqList *seqList, size_t pos, SLDataType value) {
    assert(seqList);
    //判断插入位置合法性
    assert(pos <= seqList->size);
    CheckCapacity(seqList);

    if (pos == 0) {
        //头插
        SeqListPushFront(seqList, value);
    } else if (pos == seqList->size) {
        //尾插
        SeqListPushBack(seqList, value);
    } else {
        //普通插入
        for (size_t index = seqList->size; index > pos; index--) {
            seqList->data[index] = seqList->data[index - 1];
        }

        // 在指定位置插入新元素
        seqList->data[pos] = value;

        // 更新顺序表大小
        seqList->size++;
    }

}

SLDataType SeqListGet(SeqList *seqList, size_t pos) {
    assert(seqList);
    assert(pos < seqList->size);

    return seqList->data[pos];
}

void SeqListErase(SeqList *seqList, size_t pos) {
    assert(seqList);
    assert(pos < seqList->size);
    assert(!Empty(seqList));

    for (size_t index = pos; index < seqList->size - 1; index++) {
        seqList->data[index] = seqList->data[index + 1];
    }
    //更新顺序表大小
    seqList->size--;
}

void SeqListClear(SeqList *seqList) {
    assert(seqList);
    //直接将大小置为0，表示清空顺序表
    seqList->size = 0;
}

void SeqListDestroy(SeqList *seqList) {
    assert(seqList);
    //释放动态分配的数组内存
    if (seqList->data) {
        free(seqList->data);
    }
    //将顺序表的容量和大小置为0
    seqList->capacity = 0;
    seqList->size = 0;
}

void SeqListPrint(SeqList *seqList) {
    assert(seqList);
    printf("SeqList Size: %zu\n", seqList->size);
    printf("SeqList Capacity: %zu\n", seqList->capacity);
    printf("SeqList Elements: ");
    if (Empty(seqList)) {
        printf("Empty!");
    } else {
        for (size_t i = 0; i < seqList->size; i++) {
            printf("%d ", seqList->data[i]);
        }
    }
    printf("\n");
}
