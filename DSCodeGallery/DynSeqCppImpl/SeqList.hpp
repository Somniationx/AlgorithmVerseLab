#ifndef DYNSEQCPPIMPL_SEQLIST_HPP
#define DYNSEQCPPIMPL_SEQLIST_HPP

#include <iostream>

template<class T>
class SeqList {

private:
    T *_data;         // Pointer to the dynamic array that holds data
    size_t _size;     // Current size of the sequence list
    size_t _capacity; // Current capacity of the dynamic array

public:
    SeqList(); // Constructor

    // Check capacity and resize if necessary
    void CheckCapacity();

    // Check if the sequence list is empty
    bool empty();

    // Add an element to the end of the sequence list
    void push_back(T value);

    // Remove the last element from the sequence list
    void pop_back();

    // Add an element to the front of the sequence list
    void push_front(T value);

    // Remove the first element from the sequence list
    void pop_front();

    // Find the position of a given value in the sequence list
    size_t find(T value);

    // Insert an element at a specified position
    void insert(size_t pos, T value);

    // Remove an element at a specified position
    void erase(size_t pos);

    // Print the sequence list
    void print();

    // Destructor
    ~SeqList();
};

template<class T>
void SeqList<T>::print() {
    if (!empty()) {
        for (size_t index = 0; index < _size; index++) {
            std::cout << _data[index] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Empty seqList" << std::endl;
    }
}

template<class T>
SeqList<T>::SeqList():_data(nullptr), _size(0), _capacity(0) {}

template<class T>
SeqList<T>::~SeqList() {
    if (_data) {
        delete[] _data;
        _data = nullptr;
    }
    _size = 0;
    _capacity = 0;
}

template<class T>
bool SeqList<T>::empty() {
    return (_size == 0);
}

template<class T>
void SeqList<T>::CheckCapacity() {
    // Check if the array is full and needs resizing
    if (_size == _capacity) {
        // Calculate the new capacity (double the current capacity, or 4 if it's the first allocation)
        size_t newCapacity = (_capacity == 0) ? 4 : _capacity * 2;

        // Allocate a new dynamic array with the new capacity (using std::nothrow to handle allocation failure)
        T *newData = new(std::nothrow) T[newCapacity];
        if (newData == nullptr) {
            // Memory allocation failed
            std::cerr << "Memory allocation failed" << std::endl;
            std::exit(EXIT_FAILURE);
        } else {
            // Copy the existing data to the new array
            for (size_t i = 0; i < _size; ++i) {
                newData[i] = _data[i];
            }
            // Free the memory occupied by the old array
            delete[] _data;
            // Update the data pointer and capacity
            _data = newData;
            _capacity = newCapacity;
        }
    }
}

template<class T>
void SeqList<T>::push_back(T value) {
    // Check capacity and resize if necessary
    CheckCapacity();
    // Add the value to the end of the sequence list
    _data[_size++] = value;
}

template<class T>
void SeqList<T>::pop_back() {
    if (!empty()) {
        // Remove the last element from the sequence list
        --_size;
    } else {
        std::cerr << "Error: SeqList is empty, cannot pop_back()." << std::endl;
    }
}

template<class T>
void SeqList<T>::push_front(T value) {
    CheckCapacity();
    for (size_t index = _size; index > 0; index--) {
        _data[index] = _data[index - 1];
    }
    _data[0] = value;
    _size++;
}

template<class T>
void SeqList<T>::pop_front() {
    if (!empty()) {
        for (size_t index = 0; index < _size - 1; index++) {
            _data[index] = _data[index + 1];
        }
        _size--;
    } else {
        std::cerr << "Error: SeqList is empty, cannot pop_front()." << std::endl;
    }
}

template<class T>
size_t SeqList<T>::find(T value) {
    for (size_t index = 0; index < _size; index++) {
        if (_data[index] == value) {
            return index;
        }
    }
    return static_cast<size_t>(-1); // Return a specific value to indicate not found
}

template<class T>
void SeqList<T>::insert(size_t pos, T value) {
    CheckCapacity();
    if (pos <= _size) {
        for (size_t index = _size; index > pos; index--) {
            _data[index] = _data[index - 1];
        }
        _data[pos] = value;
        _size++;
    } else {
        std::cerr << "Error: Invalid insert position." << std::endl;
    }
}

template<class T>
void SeqList<T>::erase(size_t pos) {
    if (!empty()) {
        if (pos < _size) {
            for (size_t index = pos; index < _size - 1; index++) {
                _data[index] = _data[index + 1];
            }
            _size--;
        } else {
            std::cerr << "Error: Invalid erase position." << std::endl;
        }
    } else {
        std::cerr << "Error: SeqList is empty, cannot erase
