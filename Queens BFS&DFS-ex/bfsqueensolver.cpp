#include "bfsqueensolver.h" 
#include "queennode.h"
#include<queue>
#include<iostream>
using namespace std;

BFSQueenSolver::BFSQueenSolver(int size):QueenSolver(size)
{
}

BFSQueenSolver::~BFSQueenSolver()
{
}

void BFSQueenSolver::solve(){ 
    queue<QueenNode> queens;
    QueenNode n0(this->_size);
    queens.push(n0);//把初始节点放进队列
    int num=0;
    while (!queens.empty()) {
//        int num=0;
        QueenNode crntNode=queens.front();//队列头
        queens.pop();
        QueenState st=crntNode.getState();
        if(st.isTarget()){
            num++;
            cout<<num<<" ";
            st.printState();
            continue;
        }

        int i=st.getCrntQueenNum();
        for(int j=0;j<this->_size;j++){
            if(!st.conflict(i,j)){
                QueenNode child=crntNode.createChild(i,j);
                queens.push(child);
            }
        }
    }
}

