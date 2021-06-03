//
//  ChessBoard.cpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/3.
//

#include "ChessBoard.hpp"

/*
 赋值 8 * 8 checkerboard
 */
ChessBoard::ChessBoard() : available(true), squares(8), norm(squares - 1) {
    initializeBoard();
}

// n * n checkerboard
ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares - 1) {
    initializeBoard();
}

/*
 初始化棋盘
 */
void ChessBoard::initializeBoard() {
    int i;
    column = new bool[squares]; // 列是否允许数组
    positionInRow = new int[squares]; // 在行位置
    leftDiagonal = new bool[squares * 2 - 1]; // 左对角线 ????
    rightDiagonal = new bool[squares * 2 - 1]; //右对角线?????
    for (i = 0; i < squares; i++) {
        positionInRow[i] = -1; // 填充
    }
    for (i = 0; i < squares; i++) {
        column[i] = available;
    }
    for (i = 0; i < squares * 2 - 1; i++) {
        leftDiagonal[i] = rightDiagonal[i] = available;
    }
    howMany = 0;
}

/*
 下棋
 */
void ChessBoard::putQueue(int row) {
    for (int col = 0; col < squares; col++) { // 从第0列开始，左向右遍历
        if (column[col] == available && leftDiagonal[row + col] == available && rightDiagonal[row - col + norm] == available) {
            // 放到指定位置后：设置该列、右对角线，最左边斜为不可放置状态
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row + col] = !available;
            rightDiagonal[row - col + norm] = !available;
            if (row < squares - 1) {
                putQueue(row + 1);
            } else {
//                printBoard(std::cout);
            }
            column[col] = available;
            leftDiagonal[row + col] = available;
            rightDiagonal[row - col + norm] = available;
        }
    }
}

void ChessBoard::findSolutions() {
    putQueue(0); // 从第0位置
    std::cout << howMany << " solutions found.\n" ;
}

