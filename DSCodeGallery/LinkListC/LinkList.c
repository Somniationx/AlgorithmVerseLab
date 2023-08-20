#include "LinkList.h"

// 为一个新的链表节点分配内存并初始化
ListNode *buyNewNode(ListDataType value) {
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    if (newNode) {
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    } else {
        // 分配内存失败
        fprintf(stderr, "Malloc fail!\n");
//        exit(-1); // 直接结束程序
    }
}

// 打印链表的所有元素
void ListPrint(List *list) {
    List cur = *list;
    if (cur == NULL) {
        printf("Empty List！\n");
        return;
    }
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// 在链表尾部添加一个新节点
void ListPushBack(List *list, ListDataType value) {
    List cur = *list;
    ListNode *newNode = buyNewNode(value);
    // 链表为空需要改变链表指针
    if (cur == NULL) {
        (*list) = newNode;
    } else {
        // 寻找到尾节点插入节点
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

// 在链表头部添加一个新节点
void ListPushFront(List *list, ListDataType value) {
    ListNode *newNode = buyNewNode(value);
    if ((*list) == NULL) {
        (*list) = newNode;
    } else {
        newNode->next = (*list);
        (*list) = newNode;
    }
}

// 删除链表尾部的节点
void ListPopBack(List *list) {
    if ((*list) == NULL) {
        fprintf(stderr, "Empty list, cannot ListPopBack!\n");
//        exit(-1);
    } else {
        ListNode *cur = (*list);
        ListNode *pre = NULL;
        while (cur->next != NULL) {
            pre = cur;
            cur = cur->next;
        }
        if (cur == (*list)) {
            (*list) = NULL;
        } else {
            pre->next = NULL;
        }
        free(cur);
    }
}

// 删除链表头部的节点
void ListPopFront(List *list) {
    if ((*list) == NULL) {
        fprintf(stderr, "Empty list, cannot ListPopFront！\n");
//        exit(-1);
    } else {
        ListNode *temp = (*list);
        (*list) = (*list)->next;
        free(temp);
    }
}

// 在链表中查找指定的值并返回找到的节点
ListNode *ListFind(List *list, ListDataType value) {
    ListNode *cur = (*list);
    while (cur != NULL) {
        if (cur->data == value) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

// 销毁链表，释放所有节点的内存
void ListDestroy(List *list) {
    if ((*list) != NULL) {
        ListNode *cur = (*list);
        ListNode *pre = NULL;
        while (cur != NULL) {
            pre = cur;
            cur = cur->next;
            free(pre);
        }
    }
}

//// 销毁链表，释放所有节点的内存
//void ListDestroy(List* list) {
//    while (*list != NULL) {
//        ListPopFront(list);
//    }
//}

int ListLength(List *list) {
    int length = 0;
    List cur = *list;
    while (cur != NULL) {
        length++;
        cur = cur->next;
    }
    return length;
}

void ListInsertAt(List *list, int position, ListDataType value) {
    int length = ListLength(list);

    if (position < 0 || position > length) {
        fprintf(stderr, "Invalid position!\n");
        return;
    }

    ListNode *newNode = buyNewNode(value);
    if (position == 0) {
        ListPushFront(list, value);
    } else if (position == length) {
        ListPushBack(list, value);
    } else {
        List cur = *list;
        for (int i = 0; i < position - 1; i++) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}
