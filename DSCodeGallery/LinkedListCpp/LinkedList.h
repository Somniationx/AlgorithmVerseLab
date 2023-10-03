#ifndef LINKEDLISTCPP_LINKEDLIST_H
#define LINKEDLISTCPP_LINKEDLIST_H

#include <iostream>

// Definition of a linked list node
template<class T>
class Node {
public:
    T _data;          // Data stored in the node
    Node<T>* _next;   // Pointer to the next node

    // Constructor to initialize node with a value
    explicit Node(T value) : _data(value), _next(nullptr) {}
};

template<class T>
class LinkedList {
    friend class Node<T>;

private:
    Node<T>* _head;    // Pointer to the head node of the linked list

public:
    // Constructor to initialize linked list
    LinkedList() : _head(nullptr) {}

    // Destructor to free memory when linked list is destroyed
    ~LinkedList();

    // Print the contents of the linked list
    void print() const;

    // Check if the linked list is empty
    [[nodiscard]] bool empty() const;

    // Add a node at the end of the linked list
    void push_back(T value);

    // Add a node at the beginning of the linked list
    void push_front(T value);

    // Delete the last node of the linked list
    void pop_back();

    // Delete the first node of the linked list
    void pop_front();

    // Get the length of the linked list
    [[nodiscard]] int size() const;

    // Insert a node at a specific position
    void insert(int position, T value);

    // Delete a node at a specific position
    void remove(int position);

    // Find a node containing a specific value
    Node<T>* find(T value) const;
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
    return nullptr; // Node with the specified value was not found
}

template<class T>
void LinkedList<T>::remove(int position) {
    if (position < 0 || position >= size()) {
        std::cout << "Invalid deletion position!" << std::endl;
        return;
    }
    if (position == 0) {
        Node<T>* temp = _head;
        _head = _head->_next;
        delete(temp);
    }
    else {
        int count = 0;
        Node<T>* cur = _head;
        while (count < position - 1) {
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
        std::cout << "Invalid insertion position!" << std::endl;
        return;
    }
    if (position == 0) {
        push_front(value);
    }

    int count = 0;
    Node<T>* cur = _head;
    Node<T>* pre = nullptr;
    while (count < position) {
        pre = cur;
        cur = cur->_next;
        count++;
    }
    auto* newNode = new Node<T>(value);
    pre->_next = newNode;
    newNode->_next = cur;
}

template<class T>
int LinkedList<T>::size() const {
    int count = 0;
    Node<T>* cur = _head;
    while (cur != nullptr) {
        count++;
        cur = cur->_next;
    }
    return count;
}

template<class T>
void LinkedList<T>::pop_front() {
    if (_head == nullptr) {
        std::cout << "The linked list is empty, cannot perform pop_front()." << std::endl;
        return;
    }
    else {
        Node<T>* temp = _head;
        _head = _head->_next;
        delete (temp);
    }
}

template<class T>
void LinkedList<T>::pop_back() {
    if (_head == nullptr) {
        std::cout << "The linked list is empty, cannot perform pop_back()." << std::endl;
        return;
    }
    else {
        if (_head->_next == nullptr) {
            delete (_head);
            _head = nullptr;
        }
        else {
            Node<T>* cur = _head;
            Node<T>* pre = nullptr;
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
    auto* newNode = new Node<T>(value);
    newNode->_next = _head;
    _head = newNode;
}

template<class T>
void LinkedList<T>::push_back(T value) {
    auto* newNode = new Node<T>(value);
    if (_head == nullptr) {
        _head = newNode;
    }
    else {
        Node<T>* cur = _head;
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
        std::cout << "Empty linked list" << std::endl;
    }
    Node<T>* cur = _head;
    while (cur) {
        std::cout << cur->_data << " ";
        cur = cur->_next;
    }
    std::cout << std::endl;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T>* temp = _head;
    // Only enter the space release if it is not empty
    while (_head) {
        temp = _head;
        _head = _head->_next;
        delete (temp);
    }
}

#endif // LINKEDLISTCPP_LINKEDLIST_H
