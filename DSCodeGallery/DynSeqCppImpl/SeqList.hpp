#ifndef DYNSEQCPPIMPL_SEQLIST_HPP
#define DYNSEQCPPIMPL_SEQLIST_HPP

#include <iostream>

template<class T>
class SeqList {

private:
    T *_data;
    size_t _size;
    size_t _capacity;

public:
    SeqList();

    // 检查容量，如果需要，进行扩容
    void CheckCapacity();

    // 判断顺序表是否为空
    bool empty();

    // 将元素插入顺序表末尾
    void push_back(T value);

    // 删除顺序表末尾元素
    void pop_back();

    // 在顺序表头部插入元素
    void push_front(T value);

    // 删除顺序表头部元素
    void pop_front();

    // 查找给定值在顺序表中的位置
    size_t find(T value);

    // 在指定位置插入元素
    void insert(size_t pos, T value);

    // 删除指定位置的元素
    void erase(size_t pos);

    //打印顺序表
    void print();

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
    // 初始或存满数据扩容
    if (_size == _capacity) {
        size_t newCapacity = (_capacity == 0) ? 4 : _capacity * 2;
        T *newData = new(std::nothrow) T[newCapacity]; // 使用 new(std::nothrow) 来分配内存
        if (newData == nullptr) {
            // 内存分配失败
            std::cerr << "内存分配失败" << std::endl;
            // 退出程序
            std::exit(EXIT_FAILURE);
        } else {
            // 将原数据拷贝到新数组中
            for (size_t i = 0; i < _size; ++i) {
                newData[i] = _data[i];
            }
            // 释放原数组
            delete[] _data;
            // 更新指针和容量
            _data = newData;
            _capacity = newCapacity;
        }
    }
}

template<class T>
void SeqList<T>::push_back(T value) {
    // 插入数据检查容量
    CheckCapacity();
    _data[_size++] = value;
}

template<class T>
void SeqList<T>::pop_back() {
    if (!empty()) {
        --_size;
    } else {
        std::cerr << "Error: SeqList is empty, cannot pop_back()." << std::endl;
    }
}

template<class T>
void SeqList<T>::push_front(T value) {
    CheckCapacity();
    for (size_t index = _size; index > 0; --index) {
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
    return static_cast<size_t>(-1); // 返回特定值表示未找到
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
        std::cerr << "Error: SeqList is empty, cannot erase(size_t value)." << std::endl;
    }
}


#endif //DYNSEQCPPIMPL_SEQLIST_HPP
