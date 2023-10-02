#ifndef QUEUE_H
#define QUEUE_H

// Data type stored in the queue
typedef int QDataType;

// Linked structure: represents a queue node
typedef struct QListNode
{
    struct QListNode* _pNext; // Pointer to the next node
    QDataType _data;          // Data stored in the node
} QNode;

// Queue structure
typedef struct Queue
{
    QNode* _front; // Queue head pointer, points to the head node of the queue
    QNode* _rear;  // Queue rear pointer, points to the tail node of the queue
} Queue;

void QueueInit(Queue* q);                     // Initialize the queue
void QueuePush(Queue* q, QDataType data);     // Enqueue at the rear of the queue
void QueuePop(Queue* q);                      // Dequeue from the front of the queue
QDataType QueueFront(Queue* q);               // Get the element at the front of the queue
QDataType QueueBack(Queue* q);                // Get the element at the rear of the queue
int QueueSize(Queue* q);                      // Get the number of valid elements in the queue
int QueueEmpty(Queue* q);                     // Check if the queue is empty
void QueueDestroy(Queue* q);                  // Destroy the queue

#endif // QUEUE_H
