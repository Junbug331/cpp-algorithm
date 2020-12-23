/*
grid : 2^n * 2^n



upper left -> upper right -> lower left -> lower right  

Z shape

n = 2, 2^2 = 4 ==> 4 * 4 grid

1  2  5  6
3  4  7  8
9  10 13 14
11 12 15 16

getValue(2, 3, 4) = 14
getValue(2, 2, 2) = 4

n = 3, 2^3 = 8 ==> 8 * 8 grid

1  2  5  6  9 10 13 14
3  4  7  8 11 12 15 16
... ...
... 
...

[1stCase]  [2ndCase]
[r_Upper]  [r_Upper]
[c_Left]   [c_Right]

[3rdCase]  [4thCase]
[r_Lower]  [r_Lower]
[c_Left]   [c_Right]
*/

#include <iostream>
using namespace std;

int getValue(int n, int r, int c)
{
    if (n == 0)
        return 1;
    
    // when r is in Upper 
    if (r <= 1 << (n-1)) // = if ( r <= 2^(n-1) )
    {
        // when c is in Left
        if (c <= 1 << (n-1)) // = if ( c <= 2^(n-1) )
            return getValue(n-1, r, c); // [1stCase]
        
        // when r is in Upper and c is in Right ==>if ( c > 2^(n-1) )
        // 2^(n-1) * 2^(n-1) = 2^(2n-2)
        // 2^(2n-2) = 2 ^ (2*n-2)
        return (1 << (2*n-2)) + getValue( n-1, r, c - (1 << (n-1)) ); // [2ndCase]
    }

    // when r is in Lower
    // when c is in Left
    if (c <= (1 << (n-1)) )
        return (1 << (2*n-1)) + getValue(n-1, r - (1 << (n-1)), c); // [3rdCase]
    
    // when r is in Lower and c is in Right
    return 3 * (1 << (2*n-2)) + getValue(n-1, r - (1 << (n-1)), c - (1 << (n-1)));
}



int main()
{
    //getValue(2, 3, 4) = 14
    //getValue(2, 2, 2) = 4
    cout << getValue(2, 3, 4) << "\n";
    cout << getValue(2, 2, 2) << "\n";
    return 0;
}
//getValue(2, 3, 4) = 14
//getValue(2, 2, 2) = 4