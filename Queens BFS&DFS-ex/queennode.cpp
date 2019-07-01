#include "queennode.h"

QueenNode::QueenNode(int size):_state(size)
{
}

QueenNode::~QueenNode()
{
}

QueenNode::QueenNode(const QueenNode &node):_state(node._state){
}

QueenNode QueenNode::createChild(int i, int j){
    QueenNode child(*this);//创造子节点，就是更改搜索条件
    child._state.placeQueen(i,j);
    return child;
}

QueenState & QueenNode::getState(){
    return this->_state;
}
