#ifndef QUEENNODE_H
#define QUEENNODE_H

#include "queenstate.h"

class QueenNode
{
public:
    QueenNode(int size);
    ~QueenNode();
    QueenNode(const QueenNode & node);
    QueenNode createChild(int i, int j);
        //通过改变一个皇后的位置来得到一个新的节点
        //输入参数 i, j: 将第 i 行的皇后放在第 j 列
    QueenState & getState();

private:
    QueenState _state;
};

#endif // QUEENNODE_H
