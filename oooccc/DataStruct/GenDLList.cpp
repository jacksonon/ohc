//
//  GenDLList.cpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

#include "GenDLList.hpp"


template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el) {
    if (tail != 0) { // 非空
        /*
         新建双向节点：
         1.值设置为el
         2. *next设置为0
         3. *prev设置为tail(原尾节点)
         4. 原尾节点 = tail->prev ; 将原尾结点的next指针指向新创建的tail地址；
         */
        tail = new DLLNode<T>(el, 0, tail); // 新节点
        tail->prev->next = tail; // 连接节点
    } else {
        head = tail = new DLLNode<T>(el);
    }
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail() {
    T el = tail->info;
    if (head == tail) { // 处理一个节点的情况
        delete head; // 直接删除头然后重置节点
        head = tail = 0;
    } else { // 处理多节点情况
        tail = tail->prev; // 尾结点=尾结点的前一个节点
        delete tail->next; // 删除前一个节点的next指针指向的地址
        tail->next = 0; // 将重置的尾结点的next节点指向空
    }
    return el;
}
