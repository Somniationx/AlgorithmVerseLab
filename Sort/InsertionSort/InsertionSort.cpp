void insertionSort(int arr[], int size) {
    for (int currentPos = 1; currentPos < size; currentPos++) { // Start from the second element and insert it into the sorted part
        int currentElement = arr[currentPos]; // The current element to insert
        int prevPos = currentPos - 1; // The position of the previous element

        // Find the correct position to insert the current element in the sorted part
        while (prevPos >= 0 && currentElement < arr[prevPos]) {
            arr[prevPos + 1] = arr[prevPos]; // Shift larger elements to the right
            prevPos--; // Continue comparing with the previous elements
        }

        arr[prevPos + 1] = currentElement; // Insert the current element at the correct position
    }
}

