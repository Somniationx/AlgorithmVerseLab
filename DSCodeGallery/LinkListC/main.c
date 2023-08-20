#include"LinkList.h"

int main() {
    List list = NULL;
//    ListPushBack(&list, 1);
//    ListPushBack(&list, 2);
//    ListPushBack(&list, 3);
//    ListPushBack(&list, 4);
//    ListPushBack(&list, 5);
//    ListPopBack(&list);
////    ListPopBack(&list);
//    ListNode* node = ListFind(&list, 4);
//    printf("%p\n", node);
//    ListPrint(&list);
//    ListDestroy(&list);
    ListInsertAt(&list, 6, 1);
    ListPushBack(&list, 1);
    ListPushBack(&list, 2);
    ListPushBack(&list, 3);
    ListPrint(&list);
    ListDestroy(&list);
    return 0;
}