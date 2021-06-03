//
//  GenQueue.hpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/2.
//

#ifndef GenQueue_hpp
#define GenQueue_hpp

/*
 时间O(1)
 
 标准栈：
 stack<int> stack1; 双端队列
 stack<int, vector<int>> stack2; 向量队列
 stack<int, list<int>> stack3; 链表
 
 优先队列：Priority Queue(默认使用vector实现，)
 [优先队列-几种实现方式]
 1. 进入、出队 都是O(n) 适合10个或10个以下的元素
 2. 进入排序O(n)、出队队顶O(1)
 3. 短有序链表和一个无序链表，阙值优先 O(开平方n)，适用任意尺寸队列
 4. 链表 + 指向该链表指针数组，确定新元素在链表那个范围 O(开平方n)
 
 
 双端队列 double end queue（结合向量和链表功能）
 1. 双向链表实现
 */

#include <stdio.h>
#include <list>

template <class T>
class Queue {
private:
    std::list<T> lst;
    
public:
    Queue(){}
    void clear() {
        lst.clear();
    }
    bool isEmpty() const {
        return lst.empty();
    }
    T& front() {
        return lst.front();
    }
    T dequeue() {
        T el = lst.front();
        lst.pop_front();
        return el;
    }
    void enqueue(const T &el) {
        lst.push_back(el);
    }
};

#endif /* GenQueue_hpp */
