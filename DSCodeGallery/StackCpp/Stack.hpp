#ifndef STACKCPP_STACK_HPP
#define STACKCPP_STACK_HPP

#include <iostream>

template <class T>
class Stack {
private:
    T* _data;         // Pointer to the array storing data in the stack
    size_t _top;      // Index of the top element in the stack
    size_t _capacity; // Current capacity of the array

public:
    Stack();          // Constructor
    ~Stack();         // Destructor

    void push(T value); // Push an element onto the stack
    void pop();         // Pop the top element from the stack
    bool empty();       // Check if the stack is empty
    size_t size();      // Get the number of elements in the stack
};

template <class T>
size_t Stack<T>::size() {
    return _top;
}

template <class T>
void Stack<T>::pop() {
    if (!empty()) {
        --_top; // Remove the top element from the stack
    } else {
        // Stack is empty, you can throw an exception or perform appropriate error handling
        std::cerr << "Stack is empty, cannot perform pop operation." << std::endl;
    }
}

template <class T>
bool Stack<T>::empty() {
    return _top == 0;
}

template <class T>
void Stack<T>::push(T value) {
    if (_top == _capacity) {
        size_t newCapacity = (_capacity == 0) ? 4 : _capacity * 2;
        T* newData = new(std::nothrow) T[newCapacity]; // Using std::nothrow to avoid exceptions

        if (newData) {
            // Copy data from _data to newData
            for (size_t index = 0; index < _top; ++index) {
                newData[index] = _data[index];
            }

            // Clean up old data
            delete[] _data;

            // Update member variables to reflect the new capacity and data
            _data = newData;
            _capacity = newCapacity;
        } else {
            // Handle memory allocation failure, for example:
            std::cerr << "Memory allocation failed in push." << std::endl;
            exit(-1);
        }
    }

    // Perform the push operation
    _data[_top++] = value;
}

template <class T>
Stack<T>::~Stack() {
    if (_data) {
        delete[] _data;
        _data = nullptr;
    }
    _top = 0;
    _capacity = 0;
}

template <class T>
Stack<T>::Stack() : _data(nullptr), _top(0), _capacity(0) {}

#endif // STACKCPP_STACK_HPP
