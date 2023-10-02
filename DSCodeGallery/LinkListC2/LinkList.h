#ifndef LINKLISTC2_LINKLIST_H
#define LINKLISTC2_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ListDataType;

// Structure definition for a linked list node
struct ListNode {
    ListDataType data;  // Node data
    struct ListNode* next;  // Pointer to the next node
    struct ListNode* pre;   // Pointer to the previous node
};

// Define List type using ListNode (a pointer to the head of the linked list)
typedef struct ListNode ListNode;
typedef ListNode* List;

// Create a new linked list and return a pointer to the head node
List ListCreate();

// Create a new node and return a pointer to the node
ListNode* buyNewNode(ListDataType value);

// Insert a node at the end of the linked list
void ListPushBack(List list, ListDataType value);

// Print the elements in the linked list
void ListPrint(List list);

// Insert a node at the beginning of the linked list
void ListPushFront(List list, ListDataType value);

// Delete the head node of the linked list
void ListPopFront(List list);

// Check if the linked list is empty
bool ListEmpty(List list);

// Delete the last node of the linked list
void ListPopBack(List list);

// Find a node in the linked list and return a pointer to the node; return NULL if not found
ListNode* ListFind(List list, ListDataType value);

// Destroy the entire linked list
void ListDestroy(List list);

#endif //LINKLISTC2_LINKLIST_H
