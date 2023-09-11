#ifndef STACKC_STACK_H
#define STACKC_STACK_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;
struct Stack {
    STDataType *data; // 存储栈元素的数组指针
    size_t top;       // 栈顶指针，指向下一个要被压入的位置
    size_t capacity;  // 栈的容量，当前可以存储的元素个数
};

typedef struct Stack Stack;

void StackInit(Stack *stack);                  // 初始化栈
void StackPush(Stack *stack, STDataType value); // 入栈操作
void StackPop(Stack *stack);                   // 出栈操作
size_t StackSize(Stack *stack);                // 获取栈大小
int StackEmpty(Stack *stack);                  // 判断栈是否为空
void StackDestroy(Stack *stack);               // 销毁栈

#endif //STACKC_STACK_H