//
//  GenDLList.hpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

#ifndef GenDLList_hpp
#define GenDLList_hpp

#include <stdio.h>

/*
 节点示意图
 
 |value|
 |*next| => node->next;
 |*prev| => node->prev; 如果是头节点，则node->prev == 0;
 */

// 定义节点
template<class T>
class DLLNode {
public:
    T info; // 任意类型
    DLLNode *next, *prev;
    DLLNode() {
        next = prev = 0;
    }
    
    // 节点赋值：点值；后继节点；前驱节点
    DLLNode(const T& el, DLLNode *n = 0, DLLNode *p = 0) {
        // 当前节点值为 info = el;
        // 下一个节点 next = n;
        // 前一个节点 prev = p;
        info = el; next = n; prev = p;
    }
};


template<class T>
class DoublyLinkedList {
protected:
    DLLNode<T> *head, *tail; // 表头、表尾
    
    
public:
    DoublyLinkedList() {
        head = tail = 0;
    }
    void addToDLLTail(const T&); // 添加到末位
    T deleteFromDLLTail(); // 从表尾删除
};

#endif /* GenDLList_hpp */
