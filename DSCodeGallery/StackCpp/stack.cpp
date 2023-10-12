#include <iostream>
#include <stdexcept> // 引入异常处理的头文件
#include <cassert>

template<class T>
class stack {
    typedef T val_type;
private:
    val_type *_data;   // 存储栈元素的数组指针
    size_t _top;       // 栈顶指针，指向下一个可用的位置
    size_t _capacity;  // 栈的当前容量，即能容纳的元素个数
public:
    // 默认构造
    stack() : _data(nullptr), _top(0), _capacity(0) {}

    // 获取栈的大小
    [[nodiscard]] size_t size() const { return _top; }

    // 返回栈是否为空
    [[nodiscard]] bool empty() const { return _top == 0; }

    // 用于释放栈的内存的私有函数
    void clear() {
        delete[] _data;
        _top = 0;
        _capacity = 0;
        _data = nullptr;
    }

    // 析构函数，负责释放内存
    ~stack() {
        clear();
    }

    // 拷贝构造函数
    stack(const stack &other) : _data(nullptr), _top(0), _capacity(0) {
        _top = other._top;          // 复制其他栈的大小
        _capacity = other._capacity; // 复制其他栈的容量
        _data = new(std::nothrow) val_type[_capacity]; // 为当前栈分配内存

        if (!_data) {
            throw std::bad_alloc(); // 内存分配失败时，抛出标准异常
        }

        for (size_t index = 0; index < other.size(); ++index) {
            _data[index] = other._data[index]; // 复制元素
        }
    }

    // 拷贝赋值操作符
    stack &operator=(stack other) {
        swap(other);
        return *this;
    }

    // 交换当前栈和其他栈的内容
    void swap(stack &other) {
        std::swap(_data, other._data);   // 交换数据指针
        std::swap(_top, other._top);     // 交换栈顶指针
        std::swap(_capacity, other._capacity); // 交换容量
    }

    // 获取栈顶元素
    val_type top() {
        if (empty()) {
            throw std::runtime_error("Stack is empty"); // 抛出异常以处理栈为空的情况
        }
        return _data[_top - 1];
    }

    // 压入元素到栈
    void push(const val_type &val) {
        // 扩容
        if (_top == _capacity) {
            size_t new_capacity = (_capacity == 0) ? 4 : _capacity * 2;
            auto *temp_space = new(std::nothrow) val_type[new_capacity]; // 使用 std::nothrow 处理内存分配失败

            if (!temp_space) {
                throw std::bad_alloc(); // 内存分配失败时，抛出标准异常
            }

            if (_data) {
                for (size_t index = 0; index < size(); ++index) {
                    temp_space[index] = _data[index];
                }
                delete[] _data; // 释放旧的数据内存
            }
            _data = temp_space; // 更新数据指针
            _capacity = new_capacity; // 更新容量
        }
        _data[_top++] = val; // 压入元素到栈顶
    }

    // 弹出栈顶元素
    void pop() {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        _top--; // 减少栈顶指针
    }
};

void testStack() {
    try {
        stack<int> st;

        // 测试栈是否为空
        assert(st.empty() == true);

        // 压入一些元素
        st.push(1);
        st.push(2);
        st.push(3);

        // 测试栈的大小
        assert(st.size() == 3);

        // 测试栈是否为空
        assert(st.empty() == false);

        // 测试栈顶元素
        assert(st.top() == 3);

        // 弹出一个元素
        st.pop();
        assert(st.size() == 2);
        assert(st.top() == 2);

        // 弹出剩余的元素
        st.pop();
        st.pop();

        // 测试栈是否为空
        assert(st.empty() == true);

        // 尝试在空栈上调用 top() 和 pop()，应该引发异常
        try {
            st.top();
        } catch (const std::exception &e) {
            // 捕获并打印异常信息
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try {
            st.pop();
        } catch (const std::exception &e) {
            // 捕获并打印异常信息
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // 测试拷贝构造函数和赋值操作符
        stack<int> st2 = st;
        stack<int> st3;
        st3 = st2;
        assert(st2.empty());
        assert(st3.empty());

        // 测试异常处理 - 内存分配失败
        stack<int> st4;
        try {
            for (int i = 0; i < 1000000; i++) {
                st4.push(i);
            }
        } catch (const std::exception &e) {
            // 捕获并打印异常信息
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    } catch (const std::exception &e) {
        // 捕获并打印异常信息
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    testStack();
    return 0;
}
