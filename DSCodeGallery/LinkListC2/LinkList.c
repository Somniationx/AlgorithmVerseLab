#include "LinkList.h"

// Create a new linked list and return the head node pointer
List ListCreate() {
    // Allocate memory to store the head node
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    if (head) {
        head->next = head;  // The next node of the head points to itself
        head->pre = head;   // The previous node of the head points to itself
    } else {
        fprintf(stderr, "Malloc failed!");  // Print an error message when memory allocation fails
        exit(-1);  // Exit the program to indicate failure
    }
    return head;  // Return the head node pointer
}

// Create a new node and return the node pointer
ListNode *buyNewNode(ListDataType value) {
    // Allocate memory to store the new node
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode) {
        newNode->data = value;  // Set the data value of the new node
        newNode->next = NULL;   // Initialize the next node pointer of the new node to NULL
        newNode->pre = NULL;    // Initialize the previous node pointer of the new node to NULL
    } else {
        fprintf(stderr, "Malloc failed!");  // Print an error message when memory allocation fails
        exit(-1);  // Exit the program to indicate failure
    }
    return newNode;  // Return the new node pointer
}

// Insert a node at the end of the linked list
void ListPushBack(List list, ListDataType value) {
    assert(list);  // Assert: Ensure that the head node of the list is not NULL
    ListNode *newNode = buyNewNode(value);  // Create a new node
    ListNode *last = list->pre;  // Get the last node of the list
    newNode->pre = last;  // Set the new node's predecessor to the last node
    last->next = newNode;  // Update the successor of the last node to the new node
    list->pre = newNode;  // Update the predecessor of the list to the new node
    newNode->next = list;  // Update the successor of the new node to the head node, completing the insertion
}

// Print the elements in the linked list
void ListPrint(List list) {
    assert(list);  // Assert: Ensure that the head node of the list is not NULL
    ListNode *cur = list;  // Start traversing from the head node
    if (cur->next == list) {
        fprintf(stderr, "Empty List!");  // If the list is empty, print an error message
        return;
    }
    while (cur->next != list) {
        cur = cur->next;  // Move to the next node
        printf("%d ", cur->data);  // Print the data value of the node
    }
    printf("\n");
}

// Insert a node at the beginning of the linked list
void ListPushFront(List list, ListDataType value) {
    assert(list);  // Assert: Ensure that the head node of the list is not NULL
    ListNode *first = list->next;  // Get the first node of the list
    ListNode *newNode = buyNewNode(value);  // Create a new node
    newNode->pre = list;  // Set the predecessor of the new node to the head node
    newNode->next = first;  // Set the successor of the new node to the original first node
    list->next = newNode;  // Update the successor of the head node to the new node
    first->pre = newNode;  // Update the predecessor of the original first node to the new node
}

// Check if the linked list is empty
bool ListEmpty(List list) {
    assert(list);  // Assert: Ensure that the head node of the list is not NULL
    return (list->next == list);  // Check if the list is empty
}

// Delete the head node of the linked list
void ListPopFront(List list) {
    assert(list);  // Assert: Ensure that the head node of the list is not NULL
    if (ListEmpty(list)) {
        fprintf(stderr, "Empty list, cannot ListPopFront!\n");  // If the list is empty, print an error message
        return;
    }
    ListNode *first = list->next;  // Get the first node of the list
    list->next = first->next;  // Update the successor of the head node to the second node
    first->next->pre = list;  // Update the predecessor of the second node to the head node
    free(first);  // Free the memory of the original first node
}

// Delete the last node of the linked list
void ListPopBack(List list) {
    assert(list);  // Assert: Ensure that the head node of the list is not NULL
    ListNode *last = list->pre;  // Get the last node of the list
    last->pre->next = list;  // Update the successor of the second-to-last node to the head node
    list->pre = last->pre;  // Update the predecessor of the head node to the second-to-last node
    free(last);  // Free the memory of the last node
}

// Find a node in the linked list and return a pointer to the node; return NULL if not found
ListNode *ListFind(List list, ListDataType value) {
    assert(list);  // Assert: Ensure that the head node of the list is not NULL
    if (ListEmpty(list)) return NULL;  // If the list is empty, return NULL directly
    ListNode *cur = list;  // Start from the head node
    while (cur->next != list) {
        cur = cur->next;  // Move to the next node
        if (cur->data == value) {
            return cur;  // If the target value is found, return a pointer to the node
        }
    }
    return NULL;  // If not found, return NULL
}

// Destroy the entire linked list
void ListDestroy(List list) {
    assert(list);  // Assert: Ensure that the head node of the list is not NULL
    ListNode *cur = list->next;  // Start from the first node
    while (cur != list) {
        ListNode *next = cur->next;  // Save a pointer to the next node
        free(cur->pre);  // Free the memory of the current node's predecessor
        cur = next;  // Move to the next node
    }
    free(cur);  // Free the memory of the last node
    list->next = NULL;  // Clear the successor pointer of the head node
    list->pre = NULL;   // Clear the predecessor pointer of the head node
}
