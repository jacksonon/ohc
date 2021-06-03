//
//  GenArrayQueue.hpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/2.
//

#ifndef GenArrayQueue_hpp
#define GenArrayQueue_hpp

#include <stdio.h>

template <class T, int size = 100>
class ArrayQueue {
private:
    int first, last;
    T storage[size]; // 创建数组
    
public:
    ArrayQueue() {
        first = last = -1;
    }
    void enqueue(T);
    T dequeue();
    bool isFull() {
        return (first == 0 && last == size - 1) || first == last + 1;
    }
    bool isEmpty() {
        return first == -1;
    }
};

#endif /* GenArrayQueue_hpp */
