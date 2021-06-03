//
//  IntSLList.hpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

#ifndef IntSLList_hpp
#define IntSLList_hpp

#include <stdio.h>
/*
 单向链表实现
 
 前驱节点 、 后继节点
 */

class IntSLLNode {
public:
    int info;
    IntSLLNode *next;
    
    IntSLLNode() {
        next = 0;
    }
    
    IntSLLNode(int el, IntSLLNode *ptr = 0) {
        info = el; next = ptr; // 当前节点值为info， 下一个节点为ptr
    }
};

class IntSLList {
private:
    IntSLLNode *head, *tail;
public:
    IntSLList() {
        head = tail = 0;
    }
    ~IntSLList();
    int isEmpty() {
        return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const; // 只读函数
    void myList();
};

#endif /* IntSLList_hpp */
