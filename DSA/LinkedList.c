#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty();

bool IsEmpty(List L);

bool IsLast(Position P, List L);

Position Find(ElementType X, List L);

Position FindPrevious(ElementType X, List L);

void Delete(ElementType X, List L);

Position Insert(ElementType X, List L, Position P);

void DeleteList(List L);

Position Header(List L);

Position First(List L);

Position Advance(Position P);

ElementType Retrieve(Position P);

int Count(List L);

void Reverse(List L);

void Append(List L1, List L2);

void Sort(List L);

List Copy(List L);

List Merge(List L1, List L2);

ElementType FindMax(List L);

void RemoveDuplicates(List L);

struct Node {
    ElementType Element;
    Position Next;
};

typedef struct Node Node;

List
MakeEmpty(void) {
    List L = malloc(sizeof(struct Node));
    if (L == NULL) {
        perror("Out of space!!!\n");
        exit(1); // Terminate the program on memory allocation failure
    }
    L->Next = NULL;
    return L;
}

/* Return true if L is Empty */
/* Parameter is unused in this implementation */
bool
IsEmpty(List L) {
    return L->Next == NULL;
}

/* Return true if P is the last position in List L */
bool
IsLast(Position P, List L) {
    return P->Next == NULL;
}

/* Return Position of X in L; NULL if not found */
Position
Find(ElementType X, List L) {
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;

    return P;
}

/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assume a header */
Position
FindPrevious(ElementType X, List L) {
    Position P;

    P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;

    return P;
}

/* Delete first occurrence of X from L */
void
Delete(ElementType X, List L) {
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L)) {    /* X is found; delete it */
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
Position Insert(ElementType X, List L, Position P) {
    Position TmpCell;

    TmpCell = malloc(sizeof(Node));
    if (TmpCell == NULL) {
        perror("Out of space!!!");
        exit(1); // Terminate the program on memory allocation failure
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
    return TmpCell;
}


/* Get the header of L */
Position
Header(List L) {
    return L;
}

/* Return the Position of the first element */
/* Return NULL if L is empty */
Position
First(List L) {
    return L->Next;
}

/* Delete space of L which is malloced */
void
DeleteList(List L) {
    Position CurCell, DelCell;

    CurCell = L->Next;

    while (CurCell != NULL) {
        DelCell = CurCell;
        CurCell = CurCell->Next;
        free(DelCell);
    }

    /* Free the head node of L */
    free(L);
}

/* Advance to the next position */
Position
Advance(Position P) {
    if (P == NULL) {
        perror("Attempted to advance a NULL position\n");
        return NULL;
    }
    return P->Next;
}

/* Retrieve the element at a given position */
ElementType
Retrieve(Position P) {
    if (P == NULL) {
        perror("Attempted to retrieve from a NULL position\n");
        return -1; // Assuming -1 as an error value for ElementType
    }
    return P->Element;
}

/* Count the number of elements in the list */
int
Count(List L) {
    int count = 0;
    Position P = L->Next;
    while (P != NULL) {
        count++;
        P = P->Next;
    }
    return count;
}

/* Append the second list to the end of the first list */
void
Append(List L1, List L2) {
    Position P = L1;
    while (P->Next != NULL) {
        P = P->Next;
    }
    P->Next = L2->Next;
    free(L2);
}

/* Reverse the order of elements in the list */
void
Reverse(List L) {
    if (L->Next == NULL || L->Next->Next == NULL) {
        return; // Nothing to reverse
    }

    Position prev = NULL;
    Position current = L->Next;
    Position next = NULL;

    while (current != NULL) {
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
    }

    L->Next = prev;
}

/* Sort the elements in the list in ascending order */
void
Sort(List L) {
    if (L->Next == NULL || L->Next->Next == NULL) {
        return; // List is already sorted
    }

    Position current, index;
    ElementType temp;

    for (current = L->Next; current != NULL; current = current->Next) {
        for (index = current->Next; index != NULL; index = index->Next) {
            if (current->Element > index->Element) {
                temp = current->Element;
                current->Element = index->Element;
                index->Element = temp;
            }
        }
    }
}

/* Create a new list with the same elements as the original list */
List
Copy(List L) {
    List newL = MakeEmpty();
    Position source = L->Next;
    Position dest = newL;

    while (source != NULL) {
        dest = Insert(source->Element, newL, dest);
        source = source->Next;
    }

    return newL;
}

/* Merge two sorted lists into a single sorted list */
List
Merge(List L1, List L2) {
    List mergedList = MakeEmpty();
    Position current1 = L1->Next;
    Position current2 = L2->Next;
    Position currentMerged = Header(mergedList);

    while (current1 != NULL && current2 != NULL) {
        if (current1->Element < current2->Element) {
            currentMerged = Insert(current1->Element, mergedList, currentMerged);
            current1 = current1->Next;
        } else {
            currentMerged = Insert(current2->Element, mergedList, currentMerged);
            current2 = current2->Next;
        }
    }

    // Append remaining elements from L1 or L2
    while (current1 != NULL) {
        currentMerged = Insert(current1->Element, mergedList, currentMerged);
        current1 = current1->Next;
    }

    while (current2 != NULL) {
        currentMerged = Insert(current2->Element, mergedList, currentMerged);
        current2 = current2->Next;
    }

    return mergedList;
}

/* Find the maximum element in the list */
ElementType
FindMax(List L) {
    if (IsEmpty(L)) {
        perror("List is empty.\n");
        exit(1); // Terminate the program on error
    }

    ElementType max = L->Next->Element;
    Position P = L->Next;

    while (P != NULL) {
        if (P->Element > max) {
            max = P->Element;
        }
        P = P->Next;
    }

    return max;
}

/* Remove duplicate elements from the list */
void
RemoveDuplicates(List L) {
    Position current = L->Next;
    while (current != NULL) {
        Position runner = current;
        while (runner->Next != NULL) {
            if (runner->Next->Element == current->Element) {
                Position duplicate = runner->Next;
                runner->Next = runner->Next->Next;
                free(duplicate);
            } else {
                runner = runner->Next;
            }
        }
        current = current->Next;
    }
}

int main() {
    List myList = MakeEmpty();
    Position p = Header(myList);

    Insert(1, myList, p);
    Insert(2, myList, First(myList));
    Insert(3, myList, First(myList));

    printf("List: ");
    for (Position pos = First(myList); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    Delete(2, myList);

    printf("List after deleting 2: ");
    for (Position pos = First(myList); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    // Test Count function
    printf("Number of elements in the list: %d\n", Count(myList));

    // Test Reverse function
    Reverse(myList);
    printf("Reversed list: ");
    for (Position pos = First(myList); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    // Test Append function
    List otherList = MakeEmpty();
    Insert(4, otherList, Header(otherList));
    Insert(5, otherList, Header(otherList));

    printf("Original list: ");
    for (Position pos = First(myList); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    printf("Second list: ");
    for (Position pos = First(otherList); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    Append(myList, otherList);

    printf("List after appending the second list: ");
    for (Position pos = First(myList); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    // Test Sort function
    Sort(myList);
    printf("Sorted list: ");
    for (Position pos = First(myList); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    // Test Copy function
    List copyList = Copy(myList);
    printf("Copied list: ");
    for (Position pos = First(copyList); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    // Test Merge function
    List list1 = MakeEmpty();
    List list2 = MakeEmpty();
    Insert(1, list1, Header(list1));
    Insert(3, list1, Header(list1));
    Insert(2, list2, Header(list2));
    Insert(4, list2, Header(list2));

    List merged = Merge(list1, list2);
    printf("Merged list: ");
    for (Position pos = First(merged); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    // Test FindMax function
    ElementType max = FindMax(myList);
    printf("Maximum element in the list: %d\n", max);

    // Test RemoveDuplicates function
    RemoveDuplicates(myList);
    printf("List after removing duplicates: ");
    for (Position pos = First(myList); pos != NULL; pos = Advance(pos)) {
        printf("%d ", Retrieve(pos));
    }
    printf("\n");

    DeleteList(myList); // Clean up the memory
    DeleteList(copyList);
    DeleteList(merged);
    DeleteList(list1);
    DeleteList(list2);
    return 0;
}
