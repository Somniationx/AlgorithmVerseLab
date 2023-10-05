#ifndef TREE_HEAP_H
#define TREE_HEAP_H

#include <iostream>
#include <cassert>

template<class T>
class Heap {
public:
    typedef T value_type;
    typedef T *pointer;
    typedef size_t size_type;

    // Constructor to initialize the heap.
    Heap() : _arr(nullptr),
             _size(0),
             _capacity(0) {

    }

    // Destructor to free memory.
    ~Heap() {
        delete[] _arr;
        _size = 0;
        _capacity = 0;
    }

    // Push an element into the heap and adjust the heap.
    void push(value_type val) {
        if (_size == _capacity) {
            size_type newCapacity = (_capacity == 0) ? 4 : _capacity * 2;
            auto temp = new(std::nothrow) value_type[newCapacity]; // Use nothrow version of new

            if (!temp) {
                // Memory allocation failed, handle the error gracefully
                std::cerr << "Memory allocation failed when pushing element. Heap is unchanged." << std::endl;
                return;
            }

            if (_arr) {
                memcpy(temp, _arr, _size * sizeof(value_type));
                delete[] _arr;
            }

            _arr = temp;
            _capacity = newCapacity;
        }

        _arr[_size] = val;
        _size++;

        adjustUp(_size - 1);
    }

    // Pop the top element from the heap and adjust the heap.
    void pop() {
        if (empty()) {
            throw std::runtime_error("Cannot pop from an empty heap!");
        }
        std::swap(_arr[0], _arr[_size - 1]);
        --_size;
        adjustDown(0);
    }

    // Adjust the heap upwards.
    void adjustUp(size_type child) {
        while (child > 0) {
            size_type parent = (child - 1) / 2;
            if (_arr[child] < _arr[parent]) {
                std::swap(_arr[child], _arr[parent]);
                child = parent;
            } else {
                break;
            }
        }
    }

    // Recursive version of adjustUp.
    void adjustUp(size_type child, int) {
        if (child == 0) {
            // Reached the top of the heap, no more recursion.
            return;
        }

        size_type parent = (child - 1) / 2;

        if (_arr[child] < _arr[parent]) {
            std::swap(_arr[child], _arr[parent]);
            adjustUp(parent); // Recursively adjust upwards.
        }
    }

    // Adjust the heap downwards.
    void adjustDown(size_type parent) {
        while (true) {
            size_type smallest = parent;
            size_type leftChild = 2 * parent + 1;
            size_type rightChild = 2 * parent + 2;

            // Find the smallest node among left and right children.
            if (leftChild < _size && _arr[leftChild] < _arr[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < _size && _arr[rightChild] < _arr[smallest]) {
                smallest = rightChild;
            }

            // If the smallest node is not the parent, swap them.
            if (smallest != parent) {
                std::swap(_arr[parent], _arr[smallest]);
                parent = smallest;
                continue;
            }
            break;  // Heap property is satisfied, exit the loop.
        }
    }

    // Recursive version of adjustDown.
    void adjustDown(size_type parent, int) {
        size_type smallest = parent;
        size_type leftChild = 2 * parent + 1;
        size_type rightChild = 2 * parent + 2;

        // Find the smallest node among left and right children.
        if (leftChild < _size && _arr[leftChild] < _arr[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < _size && _arr[rightChild] < _arr[smallest]) {
            smallest = rightChild;
        }

        // If the smallest node is not the parent, swap them and recursively adjust downwards.
        if (smallest != parent) {
            std::swap(_arr[parent], _arr[smallest]);
            adjustDown(smallest);
        }
    }

    // Get the size of the heap.
    [[nodiscard]] size_type size() const {
        return _size;
    }

    // Check if the heap is empty.
    [[nodiscard]] bool empty() const {
        return _size == 0;
    }

    // Get the top element of the heap.
    value_type top() const {
        if (empty()) {
            throw std::runtime_error("Heap is empty! Cannot get top element.");
        }
        return _arr[0];
    }

private:
    pointer _arr;
    size_type _size;
    size_type _capacity;
};

#endif //TREE_HEAP_H
