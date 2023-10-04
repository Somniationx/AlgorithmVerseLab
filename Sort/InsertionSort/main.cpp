#include <iostream>
#include <cassert>

void insertionSort(int arr[], int size);

int main() {
    // Test case 1: Basic test with an unsorted array
    int arr1[] = {2, 3, 5, 1, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSort(arr1, size1);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 3);
    assert(arr1[3] == 5);
    assert(arr1[4] == 6);
    std::cout << "Test case 1 passed" << std::endl;

    // Test case 2: Array with only one element (already sorted)
    int arr2[] = {42};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, size2);
    assert(arr2[0] == 42);
    std::cout << "Test case 2 passed" << std::endl;

    // Test case 3: Array with duplicate elements
    // "Duplicate elements" refers to elements in an array that appear more than once with the same value.
    int arr3[] = {4, 3, 4, 1, 2, 2, 3};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr3, size3);
    assert(arr3[0] == 1);
    assert(arr3[1] == 2);
    assert(arr3[2] == 2);
    assert(arr3[3] == 3);
    assert(arr3[4] == 3);
    assert(arr3[5] == 4);
    assert(arr3[6] == 4);
    std::cout << "Test case 3 passed" << std::endl;

    return 0;
}

