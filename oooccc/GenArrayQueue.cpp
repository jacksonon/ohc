//
//  GenArrayQueue.cpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/2.
//

#include "GenArrayQueue.hpp"

template <class T, int size>
void ArrayQueue<T, size>::enqueue(T el) {
    if (!isFull()) {
        // 队列未满
        if (last == size - 1 || last == -1) { // 此条件判断是空数组
            storage[0] = el;
            last = 0;
            if (first == -1) {
                first = 0; // 头部标记为插入
            }
        } else {
            storage[++last] = el; // 非空列表：last + 1 且对数组进行赋值将el插入队尾
        }
    } else {
        // 队列已满 ’ 不处理
//        std::cout << "队列已满" << std::endl;
    }
}
