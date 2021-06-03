//
//  GenStack.hpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/2.
//

#ifndef GenStack_hpp
#define GenStack_hpp

#include <stdio.h>
#include <vector> // 栈的向量实现

using namespace::std;

template <class T, int capacity = 30> // 最大30
class Stack {
private:
    vector<T> pool;
public:
    Stack() {
        // 在创建好空容器的基础上，还可以像下面这样通过调用 reserve() 成员函数来增加容器的容量
        pool.reserve(capacity);
    }
    void clear() {
        pool.clear();
    }
    bool isEmpty() const {
        return pool.empty();
    }
    T& topEL() {
        return pool.back();
    }
    T pop() {
        T el = pool.back();
        pool.pop_back();
        return el;
    }
    void push(const T &el) {
        /*
         此处可能需要插入扩容操作
         
         如果调用 reserve() 来增加容器容量，之前创建好的任何迭代器（例如开始迭代器和结束迭代器）都可能会失效，这是因为，为了增加容器的容量，vector<T> 容器的元素可能已经被复制或移到了新的内存地址。所以后续再使用这些迭代器时，最好重新生成一下。
         
         即扩容后，如果还会后续使用begin() end() 等迭代器位置。使用当前pool进行重新赋值
         */
        if (pool.size() % capacity == 0) { // 当时容量的整数倍的时候就要扩容
            pool.reserve(capacity); //扩容
        }
        pool.push_back(el);
    }
};


#endif /* GenStack_hpp */
