#include <iostream>
#include "Matrix2D.h"

using namespace std;

int main()
{
    //int a1[4][4] = {{1,7,12,10}, {11,7,-10,1}, {-2, 9,-5, 2}, {4, 14,-9, 3}};
    int a2[6][6] = {{1,7,12,10,1,0}, {11,7,-10,1,3,13}, {-2, 9,-5, 2,4,7}, {4, 14,-9, 3,13,-6}, {-7,-8,-9,12,6,4}, {2,-13,10,11,8,7}};
    
    //Matrix2D m1((int*)a1, 4 ,4);
    Matrix2D m2((int*)a2, 6, 6);
    m2.update(2,2,4,4,7);
    std::cout << "\n";
    std::cout <<"\n";
    Matrix2D::Print2DArray(Matrix2D::PropagateMatrix(m2.getUpdateMatrix(), m2.getRowNum(), m2.getColNum()), m2.getRowNum(), m2.getColNum());
    std::cout << "\n";
    std::cout << m2;
    std::cout << "\n";
    m2.buildUpdatedMatrix();
    std::cout << m2;


    return 0;
}