#ifndef STACKCPP_STACK_HPP
#define STACKCPP_STACK_HPP

#include<iostream>

template<class T>
class Stack {
private:
    T *_data;         // 栈内存储数据的数组指针
    size_t _top;      // 栈顶索引
    size_t _capacity; // 当前数组容量

public:
    Stack();          // 构造函数
    ~Stack();         // 析构函数

    void push(T value); // 将元素压入栈顶
    void pop();         // 弹出栈顶元素
    bool empty();       // 判断栈是否为空
    size_t size();      // 获取栈中元素个数
};

template<class T>
size_t Stack<T>::size() {
    return _top;
}

template<class T>
void Stack<T>::pop() {
    if (!empty()) {
        --_top; // 移除栈顶元素
    } else {
        // 栈为空，可以抛出异常或进行其他适当的错误处理
        std::cerr << "栈为空，无法执行 pop 操作。" << std::endl;
    }
}

template<class T>
bool Stack<T>::empty() {
    return _top == 0;
}

template<class T>
void Stack<T>::push(T value) {
    if (_top == _capacity) {
        size_t newCapacity = (_capacity == 0) ? 4 : _capacity * 2;
        T *newData = new(std::nothrow) T[newCapacity]; // 使用 std::nothrow 避免异常

        if (newData) {
            // 将数据从 _data 复制到 newData
            for (size_t index = 0; index < _top; ++index) {
                newData[index] = _data[index];
            }

            // 清理旧数据
            delete[] _data;

            // 更新成员变量以反映新的容量和数据
            _data = newData;
            _capacity = newCapacity;
        } else {
            // 处理内存分配失败，例如：
            std::cerr << "在 push 中内存分配失败。" << std::endl;
            exit(-1);
        }
    }

    // 执行 push 操作
    _data[_top++] = value;
}

template<class T>
Stack<T>::~Stack() {
    if (_data) {
        delete[] _data;
        _data = nullptr;
    }
    _top = 0;
    _capacity = 0;
}

template<class T>
Stack<T>::Stack(): _data(nullptr), _top(0), _capacity(0) {}

#endif //STACKCPP_STACK_HPP
