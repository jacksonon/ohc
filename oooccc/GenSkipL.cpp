//
//  GenSkipL.cpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

#include "GenSkipL.hpp"
#include <cstdlib>

// 构造
template<class T>
SkipList<T>::SkipList() {
    for (int i = 0; i < maxLevel; i++) {
        root[i] = 0;
    }
}

// 空列表判断
template <class T>
bool SkipList<T>::isEmpty() const {
    return root[0] == 0; // 如果root节点的第0个为0，没有指向其它节点，默认该列表为空
}

//

template <class T>
void SkipList<T>::choosePowers() {
    powers[maxLevel - 1] = (2 << (maxLevel -1)) - 1; // 2^maxLevel - 1；获取最大
    for (int i = maxLevel - 2, j = 0; i >= 0; i--, j++) {
        powers[i] = powers[i + 1] - (2 << j); // 2^(j+1)；自顶向下给powers赋值
    }
}

template <class T>
int SkipList<T>::chooseLevel() {
    int i, r = rand() % powers[maxLevel - 1] + 1;
    for (i = 1; i < maxLevel; i++) {
        if (r < powers[i]) { //
            return i - 1; // 返回小于最高单个节点的节点高度
        }
        return i - 1; // 返回节点最高高度
    }
}

template <class T>
T* SkipList<T>::skipListSearch(const T& key) {
    if (isEmpty()) {
        return 0;
    }
    
    nodePtr prev, curr;
    int lvl; // 寻找最高的非空
    for (lvl = maxLevel - 1; lvl >= 0 && !root[lvl]; lvl--);
    
}
