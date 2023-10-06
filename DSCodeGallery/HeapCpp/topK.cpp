#include <iostream>
#include <vector>

// Function to heapify an element at the specified index downwards
void heapifyDown(std::vector<int>& heap, size_t heapSize, size_t index);

// Build a max heap
void buildMaxHeap(std::vector<int>& heap) {
    int heapSize = heap.size();
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        heapifyDown(heap, heapSize, i);
    }
}

std::vector<int> findTopKMax(const std::vector<int>& nums, int k) {
    std::vector<int> heap(nums.begin(), nums.begin() + k); // Initial heap containing the first k elements

    // Build the initial max heap
    buildMaxHeap(heap);

    // Iterate through the remaining elements, replace the root if larger, and re-heapify
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
    }

    return heap;
}

// Build a min heap
void buildMinHeap(std::vector<int>& heap) {
    int heapSize = heap.size();
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        heapifyDown(heap, heapSize, i);
    }
}

std::vector<int> findTopKMin(const std::vector<int>& nums, int k) {
    std::vector<int> heap(nums.begin(), nums.begin() + k); // Initial heap containing the first k elements

    // Build the initial min heap
    buildMinHeap(heap);

    // Iterate through the remaining elements, replace the root if smaller, and re-heapify
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] < heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
    }

    return heap;
}
//int main() {
//    std::vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
//    int k = 3;
//    std::vector<int> topK = findTopKMax(nums, k);
//
//    std::cout << "Top " << k << " Max Values: ";
//    for (int num : topK) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
