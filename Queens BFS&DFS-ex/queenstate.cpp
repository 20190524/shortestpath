#include "queenstate.h"
#include <cassert>
#include <iostream>

using namespace std;
//这个状态有多少个皇后
QueenState::QueenState(int size)
{
    this->_size = size;   
//    this->_crntQueenNum=0;
    this->_sln = new int[this->_size];//节点个数
    for(int k=0;k<_size;k++){
        _sln[k] = -1;//初始状态为-1
    }
}

QueenState::QueenState(const QueenState &st){
    this->_size=st._size;
//    this->_crntQueenNum=st._crntQueenNum;
    this->_sln=new int[this->_size];
    for(int k=0;k<_size;k++){
        _sln[k]=st._sln[k];
    }
}

void QueenState::placeQueen(int i, int j){//在某个位置放上皇后
    _sln[i]=j;
//    setCrntQueenNum(i);
}


void QueenState::removeQueen(int i){//什么时候把皇后挪掉
    _sln[i]=-1;
}

void QueenState::printState(){    //先了解它的最终实现
//    cout<<_size<<endl;
    for(int i=0;i<_size;i++){
        cout<<_sln[i]<<" ";
    }
    cout<<endl;
}

int QueenState::getCrntQueenNum(){
//    return _crntQueenNum;
    int num=0;
    for(int c=0;c<_size;c++){
        if(_sln[c]!=-1)num+=1;//被设置过的点就不会为-1了
    }
    return num;
}

bool QueenState::conflict(int i, int j){//现有皇后和之前的不冲突
    for(int s=0;s<i;s++){
        if(s==i)return true;
    }
    for(int t=0;t<i;t++){
        if(_sln[t]==j)return true;
    }
    for(int p=0;p<i;p++){
        if((_sln[p]-j)==(p-i)||(_sln[p]-j)==(i-p))return true;
    }
    return false;
}

bool QueenState::isTarget(){//这个地方需要加什么，如何知道目标状态的大小
    if(_sln[_size-1]!=-1)return true;//最后一个不是-1了说明目标均已设置好
    return false;

}

QueenState::~QueenState(){
    delete []_sln;//有数组作为数据成员的一定要记得
}

/*void QueenState::setCrntQueenNum(int num){
    _crntQueenNum=num;
}*/
