#ifndef _MATRIX2D_H_
#define _MATRIX2D_H_

#include <iostream>

class Matrix2D
{
public:
    Matrix2D(): m_(nullptr), s_(nullptr), u_(nullptr), row_num(0), col_num(0), update_flag(false) {}
    Matrix2D(int *m, int r, int c);
    Matrix2D(int r, int c, int val);
    ~Matrix2D();

    inline int getRowNum() const { return row_num; }
    inline int getColNum() const { return col_num; }
    inline int* getUpdateMatrix() const {return u_; }
    inline int* getMatrix() const { return m_; }

    friend std::ostream& operator<< (std::ostream& os, Matrix2D& obj);

    int PartialSum(int r1, int c1, int r2, int c2);
    void update(int r1, int c1, int r2, int c2, int val);
    void buildUpdatedMatrix();

public:
    int index(int r, int c);
    static int index(int r, int c, int col_num);
    static void Print2DArray(int* arr2D, int r, int c);
    static int* PropagateMatrix(int* arr2D, int r, int c);

private:
    int *m_;
    int *s_;
    int *u_; 

    int row_num;
    int col_num;
    bool update_flag;
};

#endif