#include"LinkedList.h"

int main(){
    LinkedList<int> linkedList;
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.push_back(4);
    linkedList.push_back(5);
    linkedList.push_front(0);
    linkedList.remove(0);
    linkedList.insert(5,6);
    linkedList.print();
}