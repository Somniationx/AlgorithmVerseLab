#ifndef LINKEDLISTCPP_LINKEDLIST_H
#define LINKEDLISTCPP_LINKEDLIST_H

#include <iostream>

// 链表节点定义
template<class T>
class Node {
public:
    T _data;      // 节点存储的数据
    Node<T> *_next;  // 指向下一个节点的指针

    explicit Node(T value) : _data(value), _next(nullptr) {}
};

template<class T>
class LinkedList {
    friend class Node<T>;

private:
    Node<T> *_head;  // 链表的头节点指针
public:
    LinkedList() : _head(nullptr) {}

    ~LinkedList();

    void print() const;  // 打印链表内容

    [[nodiscard]] bool empty() const;  // 判断链表是否为空

    void push_back(T value);  // 在链表末尾添加节点

    void push_front(T value);  // 在链表头部添加节点

    void pop_back();  // 删除链表末尾节点

    void pop_front();  // 删除链表头部节点

    [[nodiscard]] int size() const;  // 获取链表长度

    void insert(int position, T value);  // 在指定位置插入节点

    void remove(int position);  // 删除指定位置的节点

    Node<T>* find(T value) const;  // 查找包含特定值的节点
};

template<class T>
Node<T>* LinkedList<T>::find(T value) const {
    Node<T>* cur = _head;
    while (cur) {
        if (cur->_data == value) {
            return cur;
        }
        cur = cur->_next;
    }
    return nullptr; // 未找到该值对应的节点
}

template<class T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= size()) {
        std::cout << "无效的删除位置！" << std::endl;
        return;
    }
    if (position == 0) {
        Node<T>* temp = _head;
        _head = _head->_next;
        delete(temp);
    } else {
        int count = 0;
        Node<T> *cur = _head;
        while (count < position - 1 ) {
            cur = cur->_next;
            count++;
        }
        Node<T>* temp = cur->_next;
        cur->_next = temp->_next;
        delete(temp);
    }
}

template<class T>
void LinkedList<T>::insert(int position, T value) {
    if (position < 0 || position > size()) {
        std::cout << "无效的插入位置！" << std::endl;
        return;
    }
    if (position == 0) {
        push_front(value);
    }

    int count = 0;
    Node<T> *cur = _head;
    Node<T> *pre = nullptr;
    while (count < position) {
        pre = cur;
        cur = cur->_next;
        count++;
    }
    auto *newNode = new Node<T>(value);
    pre->_next = newNode;
    newNode->_next = cur;
}

template<class T>
int LinkedList<T>::size() const {
    int count = 0;
    Node<T> *cur = _head;
    while (cur != nullptr) {
        count++;
        cur = cur->_next;
    }
    return count;
}

template<class T>
void LinkedList<T>::pop_front() {
    if (_head == nullptr) {
        std::cout << "链表为空，无法执行 pop_front()。" << std::endl;
        return;
    } else {
        Node<T> *temp = _head;
        _head = _head->_next;
        delete (temp);
    }
}

template<class T>
void LinkedList<T>::pop_back() {
    if (_head == nullptr) {
        std::cout << "链表为空，无法执行 pop_back()。" << std::endl;
        return;
    } else {
        if (_head->_next == nullptr) {
            delete (_head);
            _head = nullptr;
        } else {
            Node<T> *cur = _head;
            Node<T> *pre = nullptr;
            while (cur->_next != nullptr) {
                pre = cur;
                cur = cur->_next;
            }
            delete (cur);
            pre->_next = nullptr;
        }
    }
}

template<class T>
void LinkedList<T>::push_front(T value) {
    auto *newNode = new Node<T>(value);
    newNode->_next = _head;
    _head = newNode;
}

template<class T>
void LinkedList<T>::push_back(T value) {
    auto *newNode = new Node<T>(value);
    if (_head == nullptr) {
        _head = newNode;
    } else {
        Node<T> *cur = _head;
        while (cur->_next != nullptr) {
            cur = cur->_next;
        }
        cur->_next = newNode;
    }
}

template<class T>
bool LinkedList<T>::empty() const {
    return _head == nullptr;
}

template<class T>
void LinkedList<T>::print() const {
    if (empty()) {
        std::cout << "空链表" << std::endl;
    }
    Node<T> *cur = _head;
    while (cur) {
        std::cout << cur->_data << " ";
        cur = cur->_next;
    }
    std::cout << std::endl;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T> *temp = _head;
    // 非空才能进入释放空间
    while (_head) {
        temp = _head;
        _head = _head->_next;
        delete (temp);
    }
}

#endif // LINKEDLISTCPP_LINKEDLIST_H
