//
//  main.cpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

/*
 
 函数存储信息 运行时栈动态分配
 递归函数调用资深，系统如何区分局部变量？
 
 活动记录activation record(栈框架stack frame) [运行时栈]
 1. 所有局部变量内容
 2. 函数的参数值
 3. 表明在调用函数的何处重新开始的返回地址
 
 函数在执行状态下，隶属于该函数的活动记录一直存在，
 是函数的私有信息池，存储了程序正确执行并正确返回的调用它的函数所需要的所有信息
 
 寿命短，主函数寿命最长
 
 
 */

#include <iostream>
#include "IntSLList.hpp"
#include "GenDLList.hpp"
#include <list>
#include <algorithm>
#include <functional>

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
