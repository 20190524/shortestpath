#ifndef BFSQUEENSOLVER_H
#define BFSQUEENSOLVER_H
#include"queensolver.h"

class BFSQueenSolver: public QueenSolver
{
public:
    BFSQueenSolver(int size);
    ~BFSQueenSolver();
    void solve();
};

#endif // BFSQUEENSOLVER_H
