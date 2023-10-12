#include <cstddef>
#include <stdexcept> // 用于异常处理
#include <iostream>

template<class T>
class QueueNode {
    typedef T ValueType; // 用于定义值类型
    typedef QueueNode *NodePtr; // 节点指针类型的别名

public:
    NodePtr _next; // 指向下一个节点的指针
    ValueType _data; // 存储数据的成员

    explicit QueueNode(ValueType val) : _next(nullptr), _data(val) {} // 构造函数，初始化节点

    ~QueueNode() = default; // 默认析构函数
};

template<class T>
class Queue {
    typedef QueueNode<T> Node; // 节点类型的别名
    typedef T ValueType; // 用于定义值类型

private:
    Node *_head; // 队列头指针
    Node *_tail; // 队列尾指针
    size_t _size; // 队列的大小

public:
    Queue() : _head(nullptr), _tail(nullptr), _size(0) {} // 构造函数，初始化队列为空

    ~Queue() {
        while (!empty()) {
            pop(); // 析构函数，释放队列中的节点
        }
    }

    void push(const ValueType &val) {
        Node *new_node = nullptr;
        try {
            new_node = new Node(val); // 创建新节点并存储数据
        } catch (const std::bad_alloc &e) {
            // 处理内存分配失败，例如记录错误或退出程序
            throw std::runtime_error("Memory allocation failed in push()");
        }

        if (_head == nullptr) {
            _head = _tail = new_node; // 队列为空时，新节点成为唯一节点
        } else {
            _tail->_next = new_node; // 将新节点链接到队尾
            _tail = new_node; // 更新队尾指针
        }
        ++_size; // 队列大小增加
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty"); // 队列为空时抛出异常
        }
        Node *del = _head; // 记录要删除的节点
        _head = _head->_next; // 更新队头指针
        delete del; // 释放节点内存
        del = nullptr; // 防止野指针
        --_size; // 队列大小减少
        if (_head == nullptr) {
            _tail = nullptr; // 如果队列为空，同时更新队尾指针
        }
    }

    ValueType front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty"); // 队列为空时抛出异常
        }
        return _head->_data; // 返回队头数据
    }

    ValueType back() {
        if (empty()) {
            throw std::out_of_range("Queue is empty"); // 队列为空时抛出异常
        }
        return _tail->_data; // 返回队尾数据
    }

    [[nodiscard]] bool empty() const {
        return _head == nullptr; // 判断队列是否为空
    }
};

int main() {
    try {
        Queue<int> q;

        // Test push and front
        q.push(1);
        q.push(2);
        q.push(3);

        std::cout << "Front of the queue: " << q.front() << std::endl; // Should be 1

        // Test pop and back
        q.pop();

        std::cout << "Front of the queue after pop: " << q.front() << std::endl; // Should be 2
        std::cout << "Back of the queue: " << q.back() << std::endl; // Should be 3

        // Test pop until the queue is empty
        while (!q.empty()) {
            q.pop();
        }

        // Attempting to pop from an empty queue should throw an exception
        // q.pop(); // Uncomment this line to test the exception

        std::cout << "Queue is empty: " << q.empty() << std::endl; // Should be 1 (true)
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
