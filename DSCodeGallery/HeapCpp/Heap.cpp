#include <iostream>
#include <cassert>
#include <new> // Include the new header for std::bad_alloc

template<class T, class Con = std::less<T>>
class heap {
    // Template class for a heap data structure with an optional comparison functor
    // 用于带可选比较函数的堆数据结构的模板类

    typedef T value_type;
    // The type of elements stored in the heap
    // 堆中存储元素的类型

    typedef T *pointer;
    // Pointer to elements
    // 元素的指针类型

    typedef size_t size_type;
    // Type for sizes and indices
    // 用于大小和索引的类型

private:
    pointer _heap;
    // Pointer to the dynamic array storing the heap elements
    // 指向动态数组的指针，用于存储堆元素

    size_type _size;
    // Current number of elements in the heap
    // 堆中当前元素数

    size_type _capacity;
    // Current capacity of the dynamic array
    // 动态数组的当前容量

public:
    heap() : _heap(nullptr), _size(0), _capacity(0) {}
    // Constructor: Initializes heap with null pointer and zero size and capacity
    // 构造函数：用空指针和零大小和容量初始化堆

    heap(const heap &other) : _heap(nullptr), _size(0), _capacity(0) {
        // Copy constructor, copies elements from another heap
        // 复制构造函数，从另一个堆中复制元素
        for (size_type index = 0; index < other._size; ++index) {
            push(other._heap[index]);
        }
    }

    void clear() {
        // Clears the heap, deallocates memory, and resets member variables
        // 清空堆，释放内存并重置成员变量
        delete[] _heap;
        _heap = nullptr;
        _size = 0;
        _capacity = 0;
    }

    ~heap() {
        clear();
    }

    void push(const value_type &val) {
        try {
            if (_size == _capacity) {
                // If the heap is full, allocate more memory
                // 如果堆已满，需要分配更多内存
                size_type new_capacity = (_capacity == 0) ? 4 : _capacity * 2;
                auto tmp = new value_type[new_capacity];
                for (size_t index = 0; index < _size; ++index) {
                    tmp[index] = _heap[index];
                }
                delete[] _heap;
                _heap = tmp;
                _capacity = new_capacity;
            }
            _heap[_size++] = val;
            adjust_up(_size - 1);
        } catch (const std::bad_alloc &e) {
            // Handle exceptions for memory allocation failure
            // 处理内存分配失败的异常
            std::cerr << "Error: Memory allocation failed (" << e.what() << ")." << std::endl;
        }
    }

    void pop() {
        if (empty()) {
            // If the heap is empty, you cannot perform a pop operation
            // 如果堆为空，无法执行 pop 操作
            std::cerr << "Error: Trying to pop from an empty heap." << std::endl;
            return;
        }
        std::swap(_heap[0], _heap[_size - 1]);
        --_size;
        adjust_down(0);
    }

    void adjust_up(size_type child) {
        size_type parent;
        while (child > 0) {
            parent = (child - 1) / 2;
            if (Con{}(_heap[child], _heap[parent])) {
                // If the child is greater than the parent (or satisfies the comparison function condition), swap them
                // 如果子节点大于父节点（或满足比较函数条件），交换它们
                std::swap(_heap[child], _heap[parent]);
                child = parent;
                continue;
            } else {
                break;
            }
        }
    }

    void adjust_down(size_type parent) {
        size_type selected = parent;
        size_type left_child = parent * 2 + 1;
        size_type right_child = left_child + 1;

        if (left_child < _size && Con{}(_heap[left_child], _heap[selected])) {
            // If the left child is less than the current selected node (or satisfies the comparison function condition), select the left child
            // 如果左子节点小于当前选定的节点（或满足比较函数条件），选择左子节点
            selected = left_child;
        }
        if (right_child < _size && Con{}(_heap[right_child], _heap[selected])) {
            // If the right child is less than the current selected node (or satisfies the comparison function condition), select the right child
            // 如果右子节点小于当前选定的节点（或满足比较函数条件），选择右子节点
            selected = right_child;
        }

        if (selected != parent) {
            // If the selected node is not the current node, swap them and continue adjusting downward
            // 如果选定的节点不是当前节点，则交换它们并继续向下调整
            std::swap(_heap[parent], _heap[selected]);
            adjust_down(selected);
        }
    }

    heap &operator=(const heap &other) {
        if (this == &other) {
            return *this;
        }
        clear();
        for (size_type index = 0; index < other._size; ++index) {
            push(other._heap[index]);
        }
        return *this;
    }

    [[nodiscard]] value_type top() const {
        if (empty()) {
            // If the heap is empty, throw an exception
            // 如果堆为空，抛出异常
            throw std::runtime_error("Heap is empty.");
        }
        return _heap[0];
    }

    [[nodiscard]] bool empty() const {
        return _size == 0;
    }

    [[nodiscard]] size_type size() const {
        return _size;
    }
};

void testHeap() {
    heap<int> myHeap;

    // Test an empty heap
    assert(myHeap.empty());

    // Test pushing elements into the heap
    myHeap.push(5);
    assert(!myHeap.empty());
    assert(myHeap.size() == 1);
    assert(myHeap.top() == 5);

    myHeap.push(3);
    assert(myHeap.size() == 2);
    assert(myHeap.top() == 3);

    myHeap.push(8);
    assert(myHeap.size() == 3);
    assert(myHeap.top() == 3);

    myHeap.push(1);
    assert(myHeap.size() == 4);
    assert(myHeap.top() == 1);

    myHeap.push(10);
    assert(myHeap.size() == 5);
    assert(myHeap.top() == 1);

    // Test popping elements from the heap
    myHeap.pop();
    assert(myHeap.size() == 4);
    assert(myHeap.top() == 3);

    myHeap.pop();
    assert(myHeap.size() == 3);
    assert(myHeap.top() == 5);

    myHeap.pop();
    assert(myHeap.size() == 2);
    assert(myHeap.top() == 8);

    myHeap.pop();
    assert(myHeap.size() == 1);
    assert(myHeap.top() == 10);

    myHeap.pop();
    assert(myHeap.empty());

    // Test copying a heap
    heap<int> copiedHeap = myHeap;
    assert(copiedHeap.empty());

    // Test clearing the heap
    copiedHeap.push(42);
    copiedHeap.clear();
    assert(copiedHeap.empty());

    // Test handling exceptions for an empty heap
    bool exceptionThrown = false;
    try {
        myHeap.pop(); // Trying to pop from an empty heap should throw an exception
    } catch (const std::runtime_error &e) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    // Test handling memory allocation failure
    heap<int> bigHeap;
    bool memoryAllocationExceptionThrown = false;
    try {
        // Push a large number of elements to trigger memory allocation failure
        for (int i = 0; i < 1000000; ++i) {
            bigHeap.push(i);
        }
    } catch (const std::exception &e) {
        // Catch and handle the memory allocation exception
        memoryAllocationExceptionThrown = true;
    }
    assert(memoryAllocationExceptionThrown);
}

int main() {
    testHeap();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
