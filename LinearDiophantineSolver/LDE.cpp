//
//  LDE.cpp
//  LinearDiophantineSolver
//
//  Created by Vijay Singh negi on 04/11/21.
//

#include "LDE.h"
#include "MathUtil.hpp"

//LDE::LDE()
//{
//    
//}

LDE::LDE(int a,int b,int c)
:mA(a),mB(b),mC(c),bHaveSolutions(false)
{
    int g = mathUtil::gcd(mA,mB);
    if(c%g==0)
        bHaveSolutions = true;
    std::cout<<"Equation "<<mA<<"x + "<<mB<<"y = "<<mC;
    if(bHaveSolutions)
        std::cout<<" have solutions"<<std::endl;
    else
        std::cout<<" do not have solutions"<<std::endl;
         
}

LDE::solution LDE::SolveForOneSolution()
{
    
    solution s(0,0);
    oneSolution = s;
    if(!bHaveSolutions)
    {
        std::cout<<"Equation "<<mA<<"x + "<<mB<<"y = "<<mC;
        std::cout<<" do not have solutions"<<std::endl;
        return s;
    }
    
    int x0,y0;
    int g = mathUtil::gcd(mA,mB,x0,y0);
    
    int x = x0*(mC/g);
    int y = y0*(mC/g);
    
    s = std::make_pair(x,y);
    
    std::cout<<"Equation "<<mA<<"x + "<<mB<<"y = "<<mC;
    std::cout<<" ("<<x<<", "<<y<< ") as one of solution"<<std::endl;
    oneSolution = s;
    return s;
}
void LDE::shiftSolution(int &x,int &y,int a,int b,int cnt)
{
    x += b*cnt;
    y -= a*cnt;
}

int LDE::GetNoOfSolutionsInRange(int xMin, int xMax, int yMin, int yMax)
{
    int SolutionCount(0);
    
    if(!bHaveSolutions)
        return SolutionCount;
    
    int g = mathUtil::gcd(mA,mB);
    int a = mA/g;
    int b = mB/g;
    
    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;
    
    int x,y;
    std::tie(x,y) = oneSolution;
    
    shiftSolution(x, y, a, b,(xMin - x) / b);
    // check if truncation caused an issue.
    if (x < xMin)
        shiftSolution(x, y, a, b, sign_b); // shift in +ve side
    if(x > xMax)
        return 0;
    int lx1 = x;
    std::cout<<"x Min in range = ("<<x<<","<<y<<")\n";
    
    shiftSolution(x, y, a, b, (xMax-x)/b);
    if (x > xMax)
        shiftSolution(x, y, a, b, -sign_b);
    
    int rx1 = x;
    std::cout<<"x Max in range = ("<<x<<","<<y<<")\n";
    
    shiftSolution(x, y, a, b, -(yMin - y)/a);
    if (y < yMin)
        shiftSolution(x, y, a, b, -sign_a);
    if(y>yMax)
        return 0;
    int lx2 = x;
    
    std::cout<<"y Min in range = ("<<x<<","<<y<<")\n";
    
    shiftSolution(x, y, a, b, -(yMax - y)/a);
    if (y > yMax)
        shiftSolution(x, y, a, b, sign_a);
    int rx2 = x;
    
    std::cout<<"y Max in range = ("<<x<<","<<y<<")\n";
    
    if (lx2 > rx2)
        std::swap(lx2, rx2);
    
    int lx = std::max(lx1, lx2);
    int rx = std::min(rx1, rx2);
    if (lx > rx)
         return 0;
    
    
    SolutionCount = (rx - lx) / abs(b) + 1;

    if(true) // print soutions
    {
        std::cout<<" Equation has "<< SolutionCount<< " solutions in range ("<<xMin<<","<<xMax<<")\n";
        shiftSolution(x, y, a, b, (lx - x)/b);
        
        int temp=0;
        while(temp++<SolutionCount)
        {
            std::cout<<temp<<". ("<<x<<","<<y<<")\n";
            shiftSolution(x, y, a, b, sign_b);
            
        }
    }
    
    return SolutionCount;
}
