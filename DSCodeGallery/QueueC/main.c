#include <stdio.h>
#include "queue.h"

int main()
{
    Queue q;
    QueueInit(&q);

    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);

    printf("队列头部元素：%d\n", QueueFront(&q));
    printf("队列尾部元素：%d\n", QueueBack(&q));
    printf("队列大小：%d\n", QueueSize(&q));

    QueuePop(&q);
    printf("出队后队列头部元素：%d\n", QueueFront(&q));

    QueueDestroy(&q);

    return 0;
}
