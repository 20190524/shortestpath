#include <iostream>
#include <stack>
#include "dfsqueensolver.h"
#include "bfsqueensolver.h"

using namespace std;

int main()
{
    BFSQueenSolver solver(8);
    solver.solve();
//    DFSQueenSolver solver(8);
//    solver.solve();
    return 0;
}

