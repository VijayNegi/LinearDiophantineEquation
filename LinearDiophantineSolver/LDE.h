//
//  LDE.h
//  LinearDiophantineSolver
//
//  Created by Vijay Singh negi on 04/11/21.
//

#ifndef LDE_hpp
#define LDE_hpp

#include <stdio.h>
#include <iostream>

/*
 Class representing Linear Diophantine equations.
 
 A Linear Diophantine Equation (in two variables) is an equation of the general form:
 ax+by=c
 where `a, b, c` are given **integers**, and `x, y` are **unknown integers**.
*/
class LDE
{
public:
    using solution = std::pair<int,int>;
    //LDE();
    LDE(int a,int b,int c);
    solution SolveForOneSolution();
    int GetNoOfSolutionsInRange(int xMin, int xMax, int yMin, int yMax);
private:
    int mA,mB,mC;
    bool bHaveSolutions;
    solution oneSolution;
    void shiftSolution(int &x,int &y,int a,int b,int cnt);
};

#endif /* LDE_hpp */
