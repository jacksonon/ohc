//
//  main.cpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

#include <iostream>
#include "IntSLList.hpp"
#include "GenDLList.hpp"

using namespace std;


void controlSLList() {
    IntSLList lt = IntSLList();
    
    lt.addToHead(10);
    lt.addToHead(9);
    lt.addToHead(8);
    lt.addToTail(7);
    lt.addToTail(6);
    
    lt.deleteFromHead();
    lt.deleteFromTail();

    lt.deleteNode(10); // 删除错误的节点，在析构释放的时候会崩溃
    lt.deleteNode(9);
    
    lt.myList();
}

void controlDLList() {
    DoublyLinkedList<int> dl = DoublyLinkedList<int>();
    dl.addToDLLTail(12);
    dl.addToDLLTail(11);
    dl.addToDLLTail(10);
    
    int value = dl.deleteFromDLLTail();
    cout << value << endl;
    
    
    DoublyLinkedList<double> ddl = DoublyLinkedList<double>();
    ddl.addToDLLTail(12.9);
    ddl.addToDLLTail(12.8);
    double ddl_value = ddl.deleteFromDLLTail();
    cout << ddl_value << endl;
}

void coutLine() {
    cout << "- - - - - - - -" << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    controlSLList();
    coutLine();
    controlDLList();
        
    return 0;
}
