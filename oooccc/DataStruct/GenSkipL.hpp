//
//  GenSkipL.hpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

#ifndef GenSkipL_hpp
#define GenSkipL_hpp

#include <stdio.h>


const int maxLevel = 4; // 最高级别

template<class T>
class SkipListNode {
public:
    T key;
    SkipListNode **next; // 二级指针 指向下一个节点的指针数组，数组大小取决于节点level
    SkipListNode() {
        
    }
};


/*
 跳跃链表：优化查找速度 ； 可替代自适应树、AVL树
 查找效率：O(lg n) 最坏 O(n)
 
 */
template <class T>
class SkipList {
private:
    typedef SkipListNode<T> *nodePtr; // 简化 SkipListNode<T>类型 为 nodePtr
    nodePtr root[maxLevel]; // 节点数组 root[?] 初始化root[?] = 0; 所有指针都指向null
    int powers[maxLevel]; // powsers[?] 调用choosePowers()方法，确定该数组
    
public:
    SkipList();
    bool isEmpty() const;
    void choosePowers(); // 放入每个范围的下限
    int chooseLevel(); // 确定插入节点的level
    T* skipListSearch(const T&);
    void skipListInsert(const T&);
};

#endif /* GenSkipL_hpp */
