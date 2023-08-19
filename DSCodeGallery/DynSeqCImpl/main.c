#include "SeqList.h"

int main() {
    SeqList seqList;
    SeqListInit(&seqList);

    // 添加元素
    SeqListPushBack(&seqList, 10);
    SeqListPushBack(&seqList, 20);
    SeqListPushBack(&seqList, 30);
    SeqListPushFront(&seqList, 5);
    SeqListPushFront(&seqList, 15);

    printf("添加元素后的顺序表：\n");
    SeqListPrint(&seqList);

    // 查找值为 20 的元素
    size_t index = SeqListFind(&seqList, 20);
    if (index != (size_t)-1) {
        printf("值 20 在索引 %zu 处找到\n", index);
    } else {
        printf("值 20 未找到\n");
    }

    // 在索引 2 处插入值 25
    SeqListInsert(&seqList, 2, 25);
    printf("在索引 2 处插入值 25 后的顺序表：\n");
    SeqListPrint(&seqList);

    // 获取位置 3 处的元素
    printf("位置 3 处的元素：%d\n", SeqListGet(&seqList, 3));

    // 删除索引 1 处的元素
    SeqListErase(&seqList, 1);
    printf("删除索引 1 处的元素后的顺序表：\n");
    SeqListPrint(&seqList);

    // 头部和尾部删除元素
    SeqListPopFront(&seqList);
    SeqListPopBack(&seqList);
    printf("头部和尾部删除元素后的顺序表：\n");
    SeqListPrint(&seqList);

    // 清空顺序表
    SeqListClear(&seqList);
    printf("清空顺序表后的状态：\n");
    SeqListPrint(&seqList);

    // 销毁顺序表
    SeqListDestroy(&seqList);

    return 0;
}
