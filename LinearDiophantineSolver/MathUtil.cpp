//
//  MathUtil.cpp
//  LinearDiophantineSolver
//
//  Created by Vijay Singh negi on 04/11/21.
//

#include "MathUtil.hpp"

namespace mathUtil
{
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    int gcd(int a,int b,int& x,int& y)
    {
        if(b==0)
        {
            x=1;
            y=0;
            return a;
        }
        int x0(0),y0(0);
        int d = gcd(b, a%b, x0, y0);
        x = y0;
        y = x0 - y0*(a/b);
        return d;
    }
}
