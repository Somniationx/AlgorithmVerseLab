#include "LinkList.h"

// 创建一个新链表，返回头结点指针
List ListCreate() {
    // 分配内存以保存头节点
    ListNode *head = (ListNode *) malloc(sizeof(ListNode));
    if (head) {
        head->next = head;  // 头节点的下一个节点指向自己
        head->pre = head;   // 头节点的前一个节点指向自己
    } else {
        fprintf(stderr, "Malloc fail!");  // 内存分配失败时打印错误信息
        exit(-1);  // 退出程序，表示失败
    }
    return head;  // 返回头节点指针
}

// 创建一个新节点，返回节点指针
ListNode *buyNewNode(ListDataType value) {
    // 分配内存以保存新节点
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    if (newNode) {
        newNode->data = value;  // 设置新节点的数据值
        newNode->next = NULL;   // 将新节点的下一个节点指针初始化为 NULL
        newNode->pre = NULL;    // 将新节点的前一个节点指针初始化为 NULL
    } else {
        fprintf(stderr, "Malloc fail!");  // 内存分配失败时打印错误信息
        exit(-1);  // 退出程序，表示失败
    }
    return newNode;  // 返回新节点指针
}

// 在链表末尾插入节点
void ListPushBack(List list, ListDataType value) {
    assert(list);  // 断言：确保链表头节点不为空
    ListNode *newNode = buyNewNode(value);  // 创建一个新节点
    ListNode *last = list->pre;  // 获取链表的最后一个节点
    newNode->pre = last;  // 设置新节点的前驱为最后一个节点
    last->next = newNode;  // 更新最后一个节点的后继为新节点
    list->pre = newNode;  // 更新链表的前驱为新节点
    newNode->next = list;  // 更新新节点的后继为头节点，完成插入
}

// 打印链表元素
void ListPrint(List list) {
    assert(list);  // 断言：确保链表头节点不为空
    ListNode *cur = list;  // 从头节点开始遍历
    if (cur->next == list) {
        fprintf(stderr, "Empty List!");  // 如果链表为空，打印错误信息
        return;
    }
    while (cur->next != list) {
        cur = cur->next;  // 移动到下一个节点
        printf("%d ", cur->data);  // 打印节点的数据值
    }
    printf("\n");
}

// 在链表头部插入节点
void ListPushFront(List list, ListDataType value) {
    assert(list);  // 断言：确保链表头节点不为空
    ListNode *first = list->next;  // 获取链表的第一个节点
    ListNode *newNode = buyNewNode(value);  // 创建一个新节点
    newNode->pre = list;  // 设置新节点的前驱为头节点
    newNode->next = first;  // 设置新节点的后继为原第一个节点
    list->next = newNode;  // 更新头节点的后继为新节点
    first->pre = newNode;  // 更新原第一个节点的前驱为新节点
}

// 检查链表是否为空
bool ListEmpty(List list) {
    assert(list);  // 断言：确保链表头节点不为空
    return (list->next == list);  // 判断链表是否为空
}

// 删除链表头部节点
void ListPopFront(List list) {
    assert(list);  // 断言：确保链表头节点不为空
    if (ListEmpty(list)) {
        fprintf(stderr, "Empty list, cannot ListPopFront!\n");  // 如果链表为空，打印错误信息
        return;
    }
    ListNode *first = list->next;  // 获取链表的第一个节点
    list->next = first->next;  // 更新头节点的后继为原第二个节点
    first->next->pre = list;  // 更新原第二个节点的前驱为头节点
    free(first);  // 释放原第一个节点的内存
}

// 删除链表末尾节点
void ListPopBack(List list) {
    assert(list);  // 断言：确保链表头节点不为空
    ListNode *last = list->pre;  // 获取链表的最后一个节点
    last->pre->next = list;  // 更新倒数第二个节点的后继为头节点
    list->pre = last->pre;  // 更新头节点的前驱为倒数第二个节点
    free(last);  // 释放最后一个节点的内存
}

// 在链表中查找节点并返回节点指针，如果没找到返回 NULL
ListNode *ListFind(List list, ListDataType value) {
    assert(list);  // 断言：确保链表头节点不为空
    if (ListEmpty(list)) return NULL;  // 如果链表为空，直接返回 NULL
    ListNode *cur = list;  // 从头节点开始遍历
    while (cur->next != list) {
        cur = cur->next;  // 移动到下一个节点
        if (cur->data == value) {
            return cur;  // 如果找到目标值，返回节点指针
        }
    }
    return NULL;  // 如果没找到，返回 NULL
}

// 销毁整个链表
void ListDestroy(List list) {
    assert(list);  // 断言：确保链表头节点不为空
    ListNode *cur = list->next;  // 从第一个节点开始
    while (cur != list) {
        ListNode *next = cur->next;  // 保存下一个节点的指针
        free(cur->pre);  // 释放当前节点的内存
        cur = next;  // 移动到下一个节点
    }
    free(cur);  // 释放最后一个节点的内存
    list->next = NULL;  // 清空头节点的后继指针
    list->pre = NULL;   // 清空头节点的前驱指针
}
