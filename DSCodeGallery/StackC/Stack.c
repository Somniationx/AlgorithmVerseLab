#include "Stack.h"

// 初始化栈
void StackInit(Stack *stack) {
    assert(stack);
    stack->data = NULL;
    stack->top = 0;
    stack->capacity = 0;
}

// 入栈操作
void StackPush(Stack *stack, STDataType value) {
    assert(stack);

    if (stack->top == stack->capacity) {
        size_t newCapacity = (stack->capacity == 0) ? 4 : stack->capacity * 2;
        STDataType *temp = (STDataType *) malloc(sizeof(STDataType) * newCapacity);
        if (temp) {
            for (size_t index = 0; index < stack->top; index++) {
                temp[index] = stack->data[index];
            }
            free(stack->data);   // 释放旧的内存
            stack->data = temp;  // 更新指针为新内存地址
            temp = NULL;
            stack->capacity = newCapacity;
        } else {
            fprintf(stderr, "Malloc failed!\n");
            return;
        }
    }

    stack->data[stack->top++] = value; // 压入元素并更新栈顶指针
}

// 出栈操作
void StackPop(Stack *stack) {
    assert(stack);

    if (!StackEmpty(stack)) {
        stack->top--; // 更新栈顶指针，实现出栈操作
    } else {
        fprintf(stderr, "Empty stack, cannot pop!\n");
    }
}

// 获取栈大小
size_t StackSize(Stack *stack) {
    assert(stack);
    return stack->top; // 返回栈顶指针的值即为栈大小
}

// 判断栈是否为空
int StackEmpty(Stack *stack) {
    assert(stack);
    return (stack->top == 0); // 栈顶指针为0表示栈为空
}

// 销毁栈
void StackDestroy(Stack *stack) {
    assert(stack);
    if (stack->data) {
        free(stack->data); // 释放栈内存
        stack->data = NULL; // 避免悬挂指针
    }
    stack->top = 0;
    stack->capacity = 0;
}