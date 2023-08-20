#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h> // 使用stdlib.h 替换 malloc.h

typedef int ListDataType;

struct ListNode {
    ListDataType data;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
typedef struct ListNode *List;

// 为一个新的链表节点分配内存并初始化
ListNode *buyNewNode(ListDataType value);

// 打印链表的所有元素
void ListPrint(List *list);

// 在链表尾部添加一个新节点
void ListPushBack(List *list, ListDataType value);

// 在链表头部添加一个新节点
void ListPushFront(List *list, ListDataType value);

// 删除链表尾部的节点
void ListPopBack(List *list);

// 删除链表头部的节点
void ListPopFront(List *list);

// 在链表中查找指定的值并返回找到的节点
ListNode *ListFind(List *list, ListDataType value);

// 销毁链表，释放所有节点的内存
void ListDestroy(List *list);

// 获取链表长度
int ListLength(List *list);

// 在指定位置插入节点
void ListInsertAt(List *list, int position, ListDataType value);

#endif // LINKED_LIST_H
