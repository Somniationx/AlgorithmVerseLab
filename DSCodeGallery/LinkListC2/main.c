#include"LinkList.h"

int main(){
    List head = ListCreate();
    ListPushBack(head, 1);
    ListPushBack(head, 2);
    ListPushBack(head, 3);
    ListPushBack(head, 4);
    ListPushBack(head, 4);
    ListPushBack(head, 4);
    ListPushBack(head, 4);
    ListPushFront(head, 0);
    ListPushFront(head, 0);
    ListPushFront(head, 9);
    ListPopFront(head);
    ListPopBack(head);
    ListPopBack(head);
    ListPopBack(head);
    ListPopBack(head);
    ListPopBack(head);
    ListPopBack(head);
    ListPopBack(head);

    ListPrint(head);
}