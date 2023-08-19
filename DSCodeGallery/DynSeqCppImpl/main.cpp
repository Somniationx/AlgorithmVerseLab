#include "SeqList.hpp"

void testSeqList() {
    // ����һ�� SeqList ����
    SeqList<int> seqList;

    // ���� push_back �� print ����
    seqList.push_back(10);
    seqList.push_back(20);
    seqList.push_back(30);
    std::cout << "˳������ݣ�";
    seqList.print();

    // ���� pop_back ����
    seqList.pop_back();
    std::cout << "˳������ݣ�";
    seqList.print();

    // ���� push_front �� pop_front ����
    seqList.push_front(5);
    seqList.push_front(15);
    std::cout << "˳������ݣ�";
    seqList.print();
    seqList.pop_front();
    std::cout << "˳������ݣ�";
    seqList.print();

    // ���� find ����
    size_t index = seqList.find(20);
    if (index != static_cast<size_t>(-1)) {
        std::cout << "Ԫ�� 20 ��λ�� " << index << std::endl;
    } else {
        std::cout << "δ�ҵ�Ԫ�� 20" << std::endl;
    }

    // ���� insert ����
    seqList.insert(1, 25);
    std::cout << "˳������ݣ�";
    seqList.print();

    // ���� erase ����
    seqList.erase(2);
    std::cout << "˳������ݣ�";
    seqList.print();
}

int main() {
    testSeqList();
    return 0;
}
