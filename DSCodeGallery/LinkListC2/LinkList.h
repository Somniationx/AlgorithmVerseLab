#ifndef LINKLISTC2_LINKLIST_H
#define LINKLISTC2_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ListDataType;

// 链表节点的结构定义
struct ListNode {
    ListDataType data;  // 节点数据
    struct ListNode *next;  // 指向下一个节点的指针
    struct ListNode *pre;   // 指向前一个节点的指针
};

// 使用 ListNode 定义 List 类型（指向链表头节点的指针）
typedef struct ListNode ListNode;
typedef ListNode *List;

// 创建一个新的链表并返回头节点指针
List ListCreate();

// 创建一个新的节点并返回节点指针
ListNode *buyNewNode(ListDataType value);

// 在链表末尾插入节点
void ListPushBack(List list, ListDataType value);

// 打印链表中的元素
void ListPrint(List list);

// 在链表头部插入节点
void ListPushFront(List list, ListDataType value);

// 删除链表头部节点
void ListPopFront(List list);

// 检查链表是否为空
bool ListEmpty(List list);

// 删除链表末尾节点
void ListPopBack(List list);

// 在链表中查找节点并返回节点指针，如果没找到返回 NULL
ListNode *ListFind(List list, ListDataType value);

// 销毁整个链表
void ListDestroy(List list);

#endif //LINKLISTC2_LINKLIST_H
