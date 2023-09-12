#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void QueueInit(Queue* q)
{
    q->_front = q->_rear = NULL; // 初始时队列为空，头尾指针都指向NULL
}

void QueuePush(Queue* q, QDataType data)
{
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    if (!newNode)
    {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }

    newNode->_data = data;
    newNode->_pNext = NULL;

    if (q->_rear == NULL)
    {
        q->_front = q->_rear = newNode;
    }
    else
    {
        q->_rear->_pNext = newNode;
        q->_rear = newNode;
    }
}

void QueuePop(Queue* q)
{
    if (QueueEmpty(q))
    {
        printf("队列为空！\n");
        return;
    }

    QNode* toDelete = q->_front; // 获取待删除的头节点
    q->_front = q->_front->_pNext; // 更新队列头指针

    free(toDelete); // 释放原头节点的内存

    if (q->_front == NULL)
    {
        q->_rear = NULL; // 如果删除后队列为空，更新尾指针
    }
}

QDataType QueueFront(Queue* q)
{
    if (QueueEmpty(q))
    {
        printf("队列为空！\n");
        exit(EXIT_FAILURE);
    }
    return q->_front->_data; // 返回队头节点的数据
}

QDataType QueueBack(Queue* q)
{
    if (QueueEmpty(q))
    {
        printf("队列为空！\n");
        exit(EXIT_FAILURE);
    }
    return q->_rear->_data; // 返回队尾节点的数据
}

int QueueSize(Queue* q)
{
    int count = 0;
    QNode* current = q->_front;
    while (current)
    {
        count++;
        current = current->_pNext;
    }
    return count;
}

int QueueEmpty(Queue* q)
{
    return q->_front == NULL; // 头指针为空表示队列为空
}

void QueueDestroy(Queue* q)
{
    while (!QueueEmpty(q))
    {
        QueuePop(q); // 逐个出队并释放节点内存
    }
}
