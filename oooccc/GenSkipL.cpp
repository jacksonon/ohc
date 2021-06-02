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
    // root[0] = 0; root[1] = 0; root[2] = 0; root[3] = 0;
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
// 构造powers塔，每个塔包含指定数量的个数
void SkipList<T>::choosePowers() {
    // 2^4 - 1 = 15个元素
    // powers[3] = 15;
    // powers[2] = powers[3] - 2 = 15 - 2 = 13;
    // powers[1] = powers[2] - 4 = 13 - 4 = 9;
    // powers[0] = powers[1] - 8 = 9 - 8 = 1;
    powers[maxLevel - 1] = (2 << (maxLevel -1)) - 1; // 2^maxLevel - 1；获取最大 => powers[3] =
    for (int i = maxLevel - 2, j = 0; i >= 0; i--, j++) { // i = 2, j = 0; i >=0 ;i--, j--
        powers[i] = powers[i + 1] - (2 << j); // 2^(j+1)；自顶向下给powers赋值
    }
}

template <class T>
// 选择级别，给node选择高度；
int SkipList<T>::chooseLevel() {
    int i, r = rand() % powers[maxLevel - 1] + 1; // 计算 0 -15 + 1 即 1-16的随机数
    for (i = 1; i < maxLevel; i++) { // 从第0行开始，确定高度
        if (r < powers[i]) { // 如果随机数r 包含在power[i]里；
            return i - 1; // 返回 powers[i] 高度，
        }
        return i - 1; // 随机数大于等于powers[i]的值，则返回i-1
    }
}

template <class T>
// 搜索值为key节点是否存在及位置地址
T* SkipList<T>::skipListSearch(const T& key) {
    if (isEmpty()) { // 空链表直接返回null节点
        return 0;
    }
    
    nodePtr prev, curr; // 构建前驱、当前节点
    int lvl; // 声明level
    for (lvl = maxLevel - 1; lvl >= 0 && !root[lvl]; lvl--); // 确定level值
    prev = curr = root[lvl];
    while (true) {
        if (key == curr->key) { // 如果最高节点的值是待寻找的，则返回值地址
            return &curr->key; // 取出值地址
        } else if (key < curr->key) { // 小于key
            if (lvl == 0) { // 如果已经查找到最底层，则返回未查询到
                return 0;
            } else if (curr == root[lvl]) { // 如果当前节点，当前节点往下移
                curr = root[--lvl];
            } else { // 如果不是当前不是最高，去最高的那个node进行继续查找
                curr = *(prev->next + --lvl);
            }
        } else { // 值大于当前level
            prev = curr; // 去下一个节点
            if (*(curr->next + lvl) != 0) { // 在同一级上的非空及诶单 或
                curr = *(curr->next + lvl);
            } else { // 去链表的下一个级别查找
                for (lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--) {
                    if (lvl >= 0) { // 持续下移curr指针
                        curr = *(curr->next + lvl);
                    } else { // 查找到最底层
                        return 0;
                    }
                }
            }
        }
    }
}

template <class T>
void SkipList<T>::skipListInsert(const T &key) {
    // 构建节点
    nodePtr curr[maxLevel], prev[maxLevel], newNode;
    
    int lvl, i;
    
    curr[maxLevel - 1] = root[maxLevel - 1];
    prev[maxLevel - 1] = 0;
    for (lvl = maxLevel - 1; lvl > 0; lvl--) {
        while (curr[lvl] && curr[lvl]->key < key) { // 去一下个几点
            prev[lvl] = curr[lvl]; // 如果小
            curr[lvl] = *(curr[lvl]->next + lvl);
        }
        if (curr[lvl] && curr[lvl]->key == key) { // 不能包含
            return;
        }
        if (lvl > 0) { // 跳转下一级
            if (prev[lvl] == 0) { // 如果是最低级别
                curr[lvl - 1] = root[lvl - 1]; // 使用一个root的链接
                prev[lvl - 1] = 0;
            } else { // 如果不是最低级别，指针交换
                curr[lvl - 1] = *(prev[lvl]->next + lvl - 1);
                prev[lvl - 1] = prev[lvl];
            }
        }
    }
    lvl = chooseLevel(); // 生成一个随机级别
    newNode = new SkipListNode<T>; // 创建跳跃node
    newNode->next = new nodePtr[sizeof(nodePtr) * (lvl + 1)]; // 跳跃node->next指针赋值
    newNode->key = key; // node节点赋值
    for (i = 0; i <= lvl; i++) { // 重构链表
        *(newNode->next + i) = curr[i]; // 获取当前节点
        if (prev[i] == 0) { // 如果前一个节点是空的，则rootNode is  newNode
            root[i] = newNode;
        } else { // 非空
            *(prev[i]->next + i) = newNode; 
        }
    }
}
