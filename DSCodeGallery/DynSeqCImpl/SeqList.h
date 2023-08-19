#ifndef DYNSEQCIMPL_SEQLIST_H
#define DYNSEQCIMPL_SEQLIST_H

#include<stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>

typedef int SLDataType;

//动态顺序表
struct SeqList {
    SLDataType *data;
    size_t size;
    size_t capacity;
};

typedef struct SeqList SeqList;

//顺序表初始化
void SeqListInit(SeqList *seqList);

//检查空间
void CheckCapacity(SeqList *seqList);

//判断顺序表是否为空
bool Empty(SeqList *seqList);

//尾部插入数据
void SeqListPushBack(SeqList *seqList, SLDataType value);

//尾部删除数据
void SeqListPopBack(SeqList *seqList);

//头部插入数据
void SeqListPushFront(SeqList *seqList, SLDataType value);

//头部删除数据
void SeqListPopFront(SeqList *seqList);

//按值查找
size_t SeqListFind(SeqList *seqList, SLDataType value);

//在顺序表pos位置插入x
void SeqListInsert(SeqList *seqList, size_t pos, SLDataType value);

//删除顺序表pos位置的值
void SeqListErase(SeqList *seqList, size_t pos);

//获取顺序表中指定位置的元素
SLDataType SeqListGet(SeqList *seqList, size_t pos);

//清空顺序表保留容量
void SeqListClear(SeqList *seqList);

//销毁顺序表释放内存
void SeqListDestroy(SeqList *seqList);

//打印顺序表中的所有元素
void SeqListPrint(SeqList *seqList);


#endif //DYNSEQCIMPL_SEQLIST_H
