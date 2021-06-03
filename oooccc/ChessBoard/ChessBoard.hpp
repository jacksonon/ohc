//
//  ChessBoard.hpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/3.
//

#ifndef ChessBoard_hpp
#define ChessBoard_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

/*
 八皇后问题
 */
class ChessBoard {
private:
    const bool available;
    const int squares, norm; // 正方形平方二次幂 、 标准
    bool *column, *leftDiagonal, *rightDiagonal; // 列 左对角线 右对角线
    int *positionInRow, howMany; //行位置 数量
    void putQueue(int row); // 下皇后
    void printBoard(std::ostream& os); // 打印表格
    void initializeBoard(); // 初始化表盘
public:
    ChessBoard(); // 传统 8 * 8 棋盘 获取
    ChessBoard(int n); // extion any size checkerboard 动态表盘获取
    void findSolutions(); // 寻找解决方案
};

#endif /* ChessBoard_hpp */
