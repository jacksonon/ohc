//
//  IntSLList.cpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

#include "IntSLList.hpp"
#include <iostream>

// 析构
IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty(); ) { // 起始头节点 ；条件非空；进行循环
        p = head->next; // 当前节点指向下一个节点
        delete head; // 删除头节点（p缓存了head的下一个节点，才可以放心删除）
        head = p; // 头节点指下一个节点
    }
}

// 头插
void IntSLList::addToHead(int el) {
    // (当前节点，下一节点）
    head = new IntSLLNode(el, head); // 新建节点
    if (tail == 0) // 尾为空表明为空链表
        tail = head; // 尾设置为head
}

// 尾插
void IntSLList::addToTail(int el) {
    if (tail != 0) { // 非空则在尾部添加一个节点
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    } else {
        head = tail = new IntSLLNode(el);
    }
    
    /*
     循环链表尾插
     */
    if (isEmpty()) {
        tail = new IntSLLNode(el); // 空链表。尾部插入一个然后自循环
        tail->next = tail;
    } else {
        /*
         1. 新建节点：值为el；节点的*next指向当前tail->next
         */
        tail->next = new IntSLLNode(el, tail->next); // 新建节点：节点的next指针指向原tail的next；
        tail = tail->next; // 移动尾指针到新节点
    }
}

// 删除头节点
int IntSLList::deleteFromHead() {
    int el = head->info;
    IntSLLNode *tmp = head; // 拿到头节点指针
    if (head == tail) { // 空列表或一个节点
        head = tail = 0; // 均置空即可
    } else {
        head = head->next; // 指向像一个节点
    }
    delete tmp; // 通过tmp指针删除该内存空间的使用
    return el;
}

// 删除尾节点
int IntSLList::deleteFromTail() {
    int el = tail->info;
    
    if (head == tail) {
        delete head; // 直接删除该节点
        head = tail = 0; // 赋值一个空节点给头尾
    } else {
        IntSLLNode *tmp;
        
        // 从头结点开始查找；当tmp节点的下一个节点不等于尾节点时持续循环；
        for (tmp = head; tmp->next != tail; tmp = tmp->next); // 寻找倒数第二个节点
        tail = tmp;
        tail->next = 0; // 节点的下一个位置指向0
    }
    return el;
}

// 删除指定节点
void IntSLList::deleteNode(int el) {
    if (head != 0) { // 非空 才需要删除
        if (head == tail && el == head->info) {
            delete head;
            head = tail = 0; // 当仅有一个节点，且该节点是待删除，直接删除头节点空间，然后重置链表
        } else if (el == head->info) {
            IntSLLNode *tmp = head;
            head = head->next; // 头结点是该节点，则头结点指向下一节点后删除头节点指针
            delete tmp;
        } else {
            IntSLLNode *pred, *tmp; // 当前节点、下一节点
            for (pred = head, tmp = head->next; // 初始指向头节点、头结点的下一个节点
                 tmp != 0 && !(tmp->info == el); // 是否继续搜索？tmp节点非空（最后一个节点）&&tmp节点的值不等于待搜索值
                 pred = pred->next, tmp = tmp->next) {// 节点右移，继续搜搜
                // 条件：非空节点&&节点的值是待搜索节点[操作：删除该节点]
                if (tmp != 0) { // 非空节点[> 找到这个节点，连接其前驱、后继节点，然后删除当前节点]
                    pred->next = tmp->next; // 排除要删除的节点，pred节点替换了tmp；删除的节点仍可通过tmp访问
                    if (tmp == tail) { // 如果当前是尾节点，则给尾结点赋值pred指针
                        tail = pred;
                    }
                    delete tmp; // 删除tmp，tmp的值待删除节点的缓存指针指向
                }
            }
        }
    }
}

// 查找节点
bool IntSLList::isInList(int el) const {
    IntSLLNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}

// 打印链表
void IntSLList::myList() {
    if (!isEmpty()) {
        IntSLLNode *tmp;
        for (tmp = head; tmp->next != 0; tmp = tmp->next) {
            std::cout << tmp->info << std::endl;
        }
    }
}

/*
 
        ->head                      ->tail
        |info|*next|  |info|*next|  |info|*next|
 循环    ->pred ->tmp
 
 */
