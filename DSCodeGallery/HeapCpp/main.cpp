#include <iostream>
#include "Heap.h"

int main() {
    // Create an integer heap
    Heap<int> intHeap;

    // Insert elements into the heap
    intHeap.push(10);
    intHeap.push(30);
    intHeap.push(20);
    intHeap.push(5);
    intHeap.push(15);

    std::cout << "Heap size: " << intHeap.size() << std::endl;

    // Print elements in the heap (before sorting)
    std::cout << "Heap elements (before sorting): ";
    while (!intHeap.empty()) {
        std::cout << intHeap.top() << " ";
        intHeap.pop();
    }
    std::cout << std::endl;

    // Re-insert elements
    intHeap.push(10);
    intHeap.push(30);
    intHeap.push(20);
    intHeap.push(5);
    intHeap.push(15);

    return 0;
}
