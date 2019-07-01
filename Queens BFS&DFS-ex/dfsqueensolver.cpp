#include "dfsqueensolver.h"
#include "queennode.h"
#include"queenstate.h"
#include<stack>
#include<iostream>
using namespace std;

DFSQueenSolver::DFSQueenSolver(int size):QueenSolver(size)
{}

DFSQueenSolver::~DFSQueenSolver()
{}

void DFSQueenSolver::solve(){
    int num=0;
    stack<QueenNode> nodes;//大概是创建QueenNode类型的栈
    QueenNode  n0(this->_size);//solver大小的节点
    nodes.push(n0);//开始创建的是没放棋子的
    while(!nodes.empty()){
        QueenNode crntNode = nodes.top();//现在节点为栈中最上面的n0
        nodes.pop();//把它弹出来
        QueenState st = crntNode.getState();//现在棋盘状态？
        if(st.isTarget()){  //判断是否为目标状态
            num++;
            cout<<num<<" ";
            st.printState();
            continue;
        }
        //如果不是目标节点则拓展
        int i = st.getCrntQueenNum();
        for (int j=0;j<this->_size;j++){ //目标状态大小
           if(!st.conflict(i,j)){   //每个位置试一下
               QueenNode child = crntNode.createChild(i,j);//若与之前不冲突，则创造新的节点
               nodes.push(child);
           }
        }
    }
}

