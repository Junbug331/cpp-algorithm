#include <iostream>
#include <vector>
#include <stdint.h>
#include <cassert>
#include <stdexcept>

int matrix_index(int r, int c, int col_num)
{
    return r * col_num + c;
}

void Print2DArray(int *m, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout.width(3);
            std::cout << *(m + matrix_index(i,j,c)) << " ";
        }
        std::cout << std::endl;
    }
}

void Rotate2DMatrix(int *m, int r, int c)
{
    if ( r != c)
        throw std::invalid_argument("r c must be equal\n");
    int size = r - 1;
    int layers = r / 2;

    for (int layer = 0; layer < layers; layer++)
    {
        for (int i = 0; i < size; i++)
        {
        }
        size -= 2;
    }
}

int main()
{
    int m3[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int m4[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    
    Print2DArray((int*)m3, 3, 3);
    std::cout << std::endl;
    Print2DArray((int*)m4, 4, 4);


    
    return 0;
}