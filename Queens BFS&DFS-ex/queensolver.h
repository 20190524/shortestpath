#ifndef QUEENSOLVER_H
#define QUEENSOLVER_H


class QueenSolver
{
public:
    QueenSolver(int size);
        //@num 皇后的个数
    ~QueenSolver();
    virtual void solve()=0;
protected:
    int _size;//保护成员

};

#endif // QUEENSOLVER_H
