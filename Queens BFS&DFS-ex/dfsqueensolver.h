#ifndef DFSQUEENSOLVER_H
#define DFSQUEENSOLVER_H
#include "queensolver.h"

class DFSQueenSolver : public QueenSolver
{
public:
    DFSQueenSolver(int size);
    ~DFSQueenSolver();
    void solve();
private:
//    int DFSsize;
};

#endif // DFSQUEENSOLVER_H
