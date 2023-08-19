#include "SeqList.h"

int main() {
    SeqList seqList;
    SeqListInit(&seqList);

    // ���Ԫ��
    SeqListPushBack(&seqList, 10);
    SeqListPushBack(&seqList, 20);
    SeqListPushBack(&seqList, 30);
    SeqListPushFront(&seqList, 5);
    SeqListPushFront(&seqList, 15);

    printf("���Ԫ�غ��˳���\n");
    SeqListPrint(&seqList);

    // ����ֵΪ 20 ��Ԫ��
    size_t index = SeqListFind(&seqList, 20);
    if (index != (size_t)-1) {
        printf("ֵ 20 ������ %zu ���ҵ�\n", index);
    } else {
        printf("ֵ 20 δ�ҵ�\n");
    }

    // ������ 2 ������ֵ 25
    SeqListInsert(&seqList, 2, 25);
    printf("������ 2 ������ֵ 25 ���˳���\n");
    SeqListPrint(&seqList);

    // ��ȡλ�� 3 ����Ԫ��
    printf("λ�� 3 ����Ԫ�أ�%d\n", SeqListGet(&seqList, 3));

    // ɾ������ 1 ����Ԫ��
    SeqListErase(&seqList, 1);
    printf("ɾ������ 1 ����Ԫ�غ��˳���\n");
    SeqListPrint(&seqList);

    // ͷ����β��ɾ��Ԫ��
    SeqListPopFront(&seqList);
    SeqListPopBack(&seqList);
    printf("ͷ����β��ɾ��Ԫ�غ��˳���\n");
    SeqListPrint(&seqList);

    // ���˳���
    SeqListClear(&seqList);
    printf("���˳�����״̬��\n");
    SeqListPrint(&seqList);

    // ����˳���
    SeqListDestroy(&seqList);

    return 0;
}
