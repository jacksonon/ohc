//
//  GenSkipL.hpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

#ifndef GenSkipL_hpp
#define GenSkipL_hpp

#include <stdio.h>

const int maxLevel = 4;

template<class T>
class SkipListNode {
public:
    T key;
    SkipListNode **next; // 二级指针
    SkipListNode() {
        
    }
};


template <class T>
class SkipList {
private:
    typedef SkipListNode<T> *nodePtr;
    nodePtr root[maxLevel]; // 节点数组
    int powers[maxLevel];
    
public:
    SkipList();
    bool isEmpty() const;
    void choosePowers();
    int chooseLevel();
    T* skipListSearch(const T&);
    void skipListInsert(const T&);
};

#endif /* GenSkipL_hpp */
