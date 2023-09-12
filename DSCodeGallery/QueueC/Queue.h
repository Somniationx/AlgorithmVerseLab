#ifndef QUEUE_H
#define QUEUE_H

// 队列中存储的数据类型
typedef int QDataType;

// 链式结构：表示队列节点
typedef struct QListNode
{
    struct QListNode* _pNext; // 指向下一个节点的指针
    QDataType _data;          // 节点存储的数据
} QNode;

// 队列的结构
typedef struct Queue
{
    QNode* _front; // 队列头指针，指向队列的头节点
    QNode* _rear;  // 队列尾指针，指向队列的尾节点
} Queue;

void QueueInit(Queue* q);                     // 初始化队列
void QueuePush(Queue* q, QDataType data);     // 队尾入队列
void QueuePop(Queue* q);                      // 队头出队列
QDataType QueueFront(Queue* q);               // 获取队列头部元素
QDataType QueueBack(Queue* q);                // 获取队列队尾元素
int QueueSize(Queue* q);                      // 获取队列中有效元素个数
int QueueEmpty(Queue* q);                     // 检测队列是否为空
void QueueDestroy(Queue* q);                  // 销毁队列

#endif // QUEUE_H
