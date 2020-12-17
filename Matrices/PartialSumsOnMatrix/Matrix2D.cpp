#include "Matrix2D.h"

Matrix2D::~Matrix2D()
{
    if (m_)
    {
        delete[] m_;
        m_ = nullptr;
    }
    if(s_)
    {
        delete[] m_;
        m_ = nullptr;
    }
    if(u_)
    {
        delete[] u_;
        u_ = nullptr;
    }
}

Matrix2D::Matrix2D(int* m, int row, int col)
{
    row_num = row;
    col_num = col;
    m_ = new int[(row_num+1)* (col_num+1)];
    s_ = nullptr;
    u_ = nullptr;
    update_flag = false;

    for (int r=0; r <= row_num; r++)
    {
        for (int c=0; c <= col_num; c++)
        {
            if (r == 0 || c == 0)
            {
                m_[index(r,c)] = 0;        
            }
                
            else
            {
                m_[index(r,c)] = m[index(r-1,c-1, col)];
            }
        }
    }
}

Matrix2D::Matrix2D(int r, int c, int val)
{
    row_num = r;
    col_num = c;
    update_flag = false;
    s_ = nullptr;
    u_ = nullptr;
    m_ = new int[(row_num+1)*(col_num+1)];
    for (int r = 0; r <= row_num; r++)
    {
        for (int c = 0; c <= col_num; c++)
        {
            if (r == 0 || c == 0)
                m_[index(r,c)] = 0;
            else
                m_[index(r,c)] = val;
        }
    }
}

std::ostream& operator << (std::ostream& os, Matrix2D& obj)
{
    for (int r = 1; r <= obj.row_num; r++)
    {
        for (int c = 1; c <= obj.col_num; c++)
        {
            os.width(3);
            os << obj.m_[obj.index(r,c)] << " ";
        }
        os << "\n";
    }
    return os;
}

int Matrix2D::PartialSum(int r1, int c1, int r2, int c2)
{
    if(s_ == nullptr)
    {
        int size = (row_num+1) * (col_num+1);
        s_ = new int[size];

        for (int i = 0; i < row_num+1; i++)
            s_[index(0,i,col_num+1)] = 0;

        for (int i = 0; i < col_num+1; i++)
            s_[index(i,0,col_num+1)] = 0;
        
        for (int r = 1; r <= row_num; r++)
        {
            for (int c = 1; c <= col_num; c++)
                s_[index(r,c)] = s_[index(r,c-1)] + s_[index(r-1,c)] + m_[index(r,c)] - s_[index(r-1, c-1)];
        }
        std::cout << "Partial Sum Matrix \n";
        Print2DArray(s_, row_num, col_num);
        std::cout << "\n";
        return s_[index(r2, c2)] - s_[index(r1-1, c2)] - s_[index(r2, c1-1)] + s_[index(r1-1, c1-1)];
    }
    // std::cout << "Partial Sum Matrix \n";

    // std::cout << "\n";
    return s_[index(r2, c2)] - s_[index(r1-1, c2)] - s_[index(r2, c1-1)] + s_[index(r1-1, c1-1)];
}

void Matrix2D::update(int r1, int c1, int r2, int c2, int val)
{
    if (u_ == nullptr)
    {
        u_ = new int[(col_num+1)*(row_num+1)];
        for (int i = 0; i < (col_num+1)*(row_num+1); i++)
            u_[i] = 0;
    }
    
    u_[index(r1, c1)] += val;
    u_[index(r1, c2+1)] -= val;
    u_[index(r2+1, c1)] -= val;
    u_[index(r2+1, c2+1)] += val;
    
    if (!update_flag)
        update_flag = true;

    std::cout << "Update Matrix" << "\n";
    Print2DArray(u_, row_num, col_num);
}

int Matrix2D::index(int r, int c)
{
    return r * (col_num + 1) + c;
}

int Matrix2D::index(int r, int c, int col)
{
    return r * col + c;
}

void Matrix2D::buildUpdatedMatrix()
{
    if (update_flag)
    {
        int* cum_u_ = PropagateMatrix(u_, row_num, col_num);
        for (int r = 1; r <= row_num; r++)
        {
            for (int c = 1; c <= col_num; c++)
            {
                m_[index(r,c)] += cum_u_[index(r,c)];
            }
        }
        update_flag = false;
    }
    
}

void Matrix2D::Print2DArray(int* arr2D, int r, int c)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            std::cout.width(3);
            std::cout << arr2D[i * (c+1) + j] <<  " ";
        }
        std::cout << "\n";
    }
}

int* Matrix2D::PropagateMatrix(int* arr2D, int rowN, int colN)
{
    int* p_arr2D = new int[(rowN+1)*(colN+1)];
    for (int r = 0; r <= rowN; r++)
    {
        for (int c = 0; c <= colN; c++)
        {
            if (r == 0 || c == 0)
                p_arr2D[index(r,c,colN+1)] = 0;
            else
                p_arr2D[index(r,c,colN+1)] = p_arr2D[index(r,c-1,colN+1)] + p_arr2D[index(r-1,c,colN+1)] + arr2D[index(r,c,colN+1)] - p_arr2D[index(r-1,c-1,colN+1)];
        }
    }

    return p_arr2D;
}