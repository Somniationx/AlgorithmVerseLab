#include <iostream>
#include <vector>

// Function to perform Heapify Down operation on a Min Heap
// This function rearranges the elements in the min heap rooted at 'index' to maintain the min heap property.
void heapifyDown(std::vector<int> &ve, size_t numItems, size_t index) {
    while (true) {
        size_t smallest = index;
        size_t leftChild = smallest * 2 + 1;
        size_t rightChild = smallest * 2 + 2;

        // Check if the left child exists and is smaller than the current smallest element
        if (leftChild < numItems && ve[smallest] > ve[leftChild]) {
            smallest = leftChild;
        }

        // Check if the right child exists and is smaller than the current smallest element
        if (rightChild < numItems && ve[smallest] > ve[rightChild]) {
            smallest = rightChild;
        }

        // If the smallest element is not the current element, swap them and continue
        if (smallest != index) {
            std::swap(ve[smallest], ve[index]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Overloaded version of heapifyDown that accepts an additional integer parameter
void heapifyDown(std::vector<int> &ve, size_t numItems, size_t index, int) {
    size_t smallest = index;
    size_t leftChild = smallest * 2 + 1;
    size_t rightChild = smallest * 2 + 2;

    // Check if the left child exists and is smaller than the current smallest element
    if (leftChild < numItems && ve[smallest] > ve[leftChild]) {
        smallest = leftChild;
    }

    // Check if the right child exists and is smaller than the current smallest element
    if (rightChild < numItems && ve[smallest] > ve[rightChild]) {
        smallest = rightChild;
    }

    // If the smallest element is not the current element, swap them and continue
    if (smallest != index) {
        std::swap(ve[smallest], ve[index]);
        heapifyDown(ve, numItems, smallest, 1);
    }
}

// Function to perform Heapify Up operation on a Max Heap
// This function rearranges the elements in the max heap rooted at 'index' to maintain the max heap property.
void heapifyUp(std::vector<int> &ve, size_t index) {
    size_t child = index;
    size_t parent = (child - 1) / 2;

    while (child > 0) {
        // Check if the child is greater than its parent, if so, swap them and continue
        if (ve[child] > ve[parent]) {
            std::swap(ve[child], ve[parent]);
            child = parent;
            parent = (child - 1) / 2;
        } else {
            break;
        }
    }
}

// Overloaded version of heapifyUp that accepts an additional integer parameter
void heapifyUp(std::vector<int> &ve, size_t index, int) {
    if (index == 0) {
        return;
    }

    size_t parentIndex = (index - 1) / 2;

    if(ve[index] < ve[parentIndex]) {
        std::swap(ve[index], ve[parentIndex]);
        heapifyUp(ve, parentIndex, 1);
    }
}

// Function to build a Min Heap
void buildMinHeap() {
    std::vector<int> ve = {1, 3, 7, 5, 2, 4, 6, 1, 1};

    size_t numItems = ve.size();

    // Perform Heapify Down for all non-leaf nodes to build the Min Heap
    for (size_t index = (numItems / 2); index > 0; --index) {
        heapifyDown(ve, numItems, index - 1);
    }

    std::cout << "Min Heap elements: ";
    for (int num: ve) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Function to build a Max Heap
void buildMaxHeap() {
    std::vector<int> ve = {1, 3, 7, 5, 2, 4, 6, 1, 1};

    size_t numItems = ve.size();

    // Perform Heapify Up for all elements to build the Max Heap
    for (size_t index = 1; index < numItems; index++) {
        heapifyUp(ve, index);
    }

    std::cout << "Max Heap elements: ";
    for (int num: ve) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

