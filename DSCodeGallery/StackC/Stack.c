#include "Stack.h"

// Initialize the stack
void StackInit(Stack *stack) {
    assert(stack);
    stack->data = NULL;
    stack->top = 0;
    stack->capacity = 0;
}

// Push operation
void StackPush(Stack *stack, STDataType value) {
    assert(stack);

    if (stack->top == stack->capacity) {
        size_t newCapacity = (stack->capacity == 0) ? 4 : stack->capacity * 2;
        STDataType *temp = (STDataType *)malloc(sizeof(STDataType) * newCapacity);
        if (temp) {
            for (size_t index = 0; index < stack->top; index++) {
                temp[index] = stack->data[index];
            }
            free(stack->data);   // Free the old memory
            stack->data = temp;  // Update the pointer to the new memory address
            temp = NULL;
            stack->capacity = newCapacity;
        } else {
            fprintf(stderr, "Malloc failed!\n");
            return;
        }
    }

    stack->data[stack->top++] = value; // Push the element and update the top pointer
}

// Pop operation
void StackPop(Stack *stack) {
    assert(stack);

    if (!StackEmpty(stack)) {
        stack->top--; // Update the top pointer to implement the pop operation
    } else {
        fprintf(stderr, "Empty stack, cannot pop!\n");
    }
}

// Get the stack size
size_t StackSize(Stack *stack) {
    assert(stack);
    return stack->top; // Return the value of the top pointer as the stack size
}

// Check if the stack is empty
int StackEmpty(Stack *stack) {
    assert(stack);
    return (stack->top == 0); // The top pointer being 0 indicates an empty stack
}

// Destroy the stack
void StackDestroy(Stack *stack) {
    assert(stack);
    if (stack->data) {
        free(stack->data); // Free the stack memory
        stack->data = NULL; // Avoid dangling pointers
    }
    stack->top = 0;
    stack->capacity = 0;
}
