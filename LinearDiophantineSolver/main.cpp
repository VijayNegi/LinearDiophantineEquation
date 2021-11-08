//
//  main.cpp
//  LinearDiophantineSolver
//
//  Created by Vijay Singh negi on 04/11/21.
//

#include <iostream>
#include "LDE.h"
// forward declaration
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a(60),b(33),c(9);
    //int a(7),b(-9),c(3);
    int xMin(-20),xMax(20),yMin(-20),yMax(20);
    //LDE eqe = LDE(3, 5, 47);
    //LDE eqe = LDE(7, -9,3);
    LDE eqe = LDE(a, b,c);
    eqe.SolveForOneSolution();
    eqe.GetNoOfSolutionsInRange(xMin, xMax, yMin, yMax);
    
    int num = find_all_solutions(a,b,c, xMin, xMax, yMin, yMax);
    std::cout<< "No of solutions of equation = "<<num<<std::endl;
    return 0;
}


int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        std::swap(lx2, rx2);
    int lx = std::max(lx1, lx2);
    int rx = std::min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / std::abs(b) + 1;
}
