//
//  GenListStack.hpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/2.
//

#ifndef GenListStack_hpp
#define GenListStack_hpp

#include <stdio.h>
#include <list>

/*
 链表形式的栈更匹配，向量可以主动指定大小和扩容，带来不必要的开销
 出栈、入栈。O(1)常数级[链表永远如此，但是如果使用向量且扩容的情况下，最坏可达到O(n)]
 */

template <class T>
class LLStack {
private:
    std::list<T> lst;
    
public:
    LLStack() {
        
    }
    void clear() {
        lst.clear();
    }
    T& topEl() {
        return lst.back();
    }
    T pop() {
        T el = lst.back();
        lst.pop_back();
        return el;
    }
    void push(const T &el) {
        lst.push_back(el);
    }
};

#endif /* GenListStack_hpp */
