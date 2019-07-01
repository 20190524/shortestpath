#ifndef QUEENSTATE_H
#define QUEENSTATE_H

class QueenState
{
public:
    QueenState(int size);
    QueenState(const QueenState & st);
    void placeQueen(int i, int j);//将第i行的皇后放在第j列
    void removeQueen(int i); //去掉第 i 行的皇后
    void printState();//打印状态内容
    int getCrntQueenNum();//当前棋盘上有多少个皇后
//    void setCrntQueenNum(int num);
    bool conflict(int i, int j);//在第i行j列放入一个新的皇后，是否与现有皇后冲突
    bool isTarget();//是否目标状态

    ~QueenState();
private:
    int _size;//棋盘大小，即最多有多少皇后
//    int _crntQueenNum;//当前棋盘皇后数量
    int * _sln;//皇后在棋盘上的摆放 _sln[i]=j, 表示第i行皇后在第j列
};

#endif // QUEENSTATE_H
