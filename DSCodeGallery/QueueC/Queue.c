#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void QueueInit(Queue* q)
{
    q->_front = q->_rear = NULL; // Initially, the queue is empty, both front and rear pointers point to NULL
}

void QueuePush(Queue* q, QDataType data)
{
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
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
        printf("Queue is empty!\n");
        return;
    }

    QNode* toDelete = q->_front; // Get the node to delete from the front
    q->_front = q->_front->_pNext; // Update the front pointer of the queue

    free(toDelete); // Free the memory of the original front node

    if (q->_front == NULL)
    {
        q->_rear = NULL; // If the queue becomes empty after deletion, update the rear pointer
    }
}

QDataType QueueFront(Queue* q)
{
    if (QueueEmpty(q))
    {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    return q->_front->_data; // Return the data of the front node
}

QDataType QueueBack(Queue* q)
{
    if (QueueEmpty(q))
    {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    return q->_rear->_data; // Return the data of the rear node
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
    return q->_front == NULL; // The front pointer being NULL indicates an empty queue
}

void QueueDestroy(Queue* q)
{
    while (!QueueEmpty(q))
    {
        QueuePop(q); // Dequeue and free node memory one by one
    }
}
