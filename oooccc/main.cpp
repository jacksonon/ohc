//
//  main.cpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

/*
 旅行：（特色为主）
 
 // 上午
 中央大街【2h】
 圣索非亚大教堂【0.5h】
 防洪胜利纪念塔 + 斯大林公园 + 松花江【1.5h】
 
 // 下午
 老道外
 龙塔
 果戈里大街
【1h】
 
 太阳岛 + 俄罗斯风情小镇
 哈尔滨极地馆
 
 */

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
 
 
 活动记录：
 1. 参数和局部变量
 2. 动态链接，指向调用程序的活动记录的指针
 3. 返回地址，可以使调用者重新获得控制权的返回地址，调用者指令的地址紧随这个调用之后
 4. 返回值：非void会有这个记录
 
 递归：
 函数名称相同
 内部：不同活动记录的调用；由系统区分；函数一个实例调用另一个实例
 
 尾递归：
 在每个函数实现的末位只使用一个递归调用。
 
 间接递归
 通过一系列其它调用来间接的调用自身
 
 嵌套递，作为函数的一个参数进行传递
 不合理递归：
 */

#include <iostream>
#include "IntSLList.hpp"
#include "GenDLList.hpp"
#include <list>
#include <algorithm>
#include <functional>
#include "ChessBoard.hpp"

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


unsigned int Fib(unsigned int n) {
    if (n < 2) {
        return n;
    } else {
        
        // 简化递归
        // 'register' storage class specifier is deprecated and incompatible with C++17 新的编译器，嫩更好的分配寄存器或RAM 寄存器可以更快的访问变量
        int i = 2, tmp, current = 1, last = 0;
        // 通过迭代来进行计算:last保存上次值
        for (; i <= n; ++i) {
            tmp = current; // 缓存当前值
            current += last; // cur = cur + 上次计算的值
            last = tmp; // 上次计算的值 = 当前值
            cout << current << endl;
        }
        return current;
        
        // 太耗时
        /*
         每个加法带有两次调用；再加上最开始的调用
         2倍 * 调用次数 - 1 去除最开始的
         2 * Fib(n + 1) - 1此函数
         */
//        return Fib(n - 2) + Fib(n - 1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*
    controlSLList();
    coutLine();
    controlDLList();
    coutLine();
    Fib(30);
//    cout << Fib(100) << endl;
     */
    
    ChessBoard().findSolutions();
    
    return 0;
}


