//
//  main.cpp
//  LinearDiophantineSolver
//
//  Created by Vijay Singh negi on 04/11/21.
//

#include <iostream>
#include "LDE.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //LDE eqe = LDE(3, 5, 47);
    LDE eqe = LDE(7, -9,3);
    eqe.SolveForOneSolution();
    int num = eqe.GetNoOfSolutionsInRange(-20, 20, -20, 20);
    std::cout<< "No of solutions of equation = "<<num<<std::endl;
    return 0;
}
