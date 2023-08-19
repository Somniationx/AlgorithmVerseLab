#include "SeqList.hpp"

void testSeqList() {
    // 创建一个 SeqList 对象
    SeqList<int> seqList;

    // 测试 push_back 和 print 函数
    seqList.push_back(10);
    seqList.push_back(20);
    seqList.push_back(30);
    std::cout << "顺序表内容：";
    seqList.print();

    // 测试 pop_back 函数
    seqList.pop_back();
    std::cout << "顺序表内容：";
    seqList.print();

    // 测试 push_front 和 pop_front 函数
    seqList.push_front(5);
    seqList.push_front(15);
    std::cout << "顺序表内容：";
    seqList.print();
    seqList.pop_front();
    std::cout << "顺序表内容：";
    seqList.print();

    // 测试 find 函数
    size_t index = seqList.find(20);
    if (index != static_cast<size_t>(-1)) {
        std::cout << "元素 20 在位置 " << index << std::endl;
    } else {
        std::cout << "未找到元素 20" << std::endl;
    }

    // 测试 insert 函数
    seqList.insert(1, 25);
    std::cout << "顺序表内容：";
    seqList.print();

    // 测试 erase 函数
    seqList.erase(2);
    std::cout << "顺序表内容：";
    seqList.print();
}

int main() {
    testSeqList();
    return 0;
}
