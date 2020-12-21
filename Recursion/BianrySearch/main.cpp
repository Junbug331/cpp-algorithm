#include <iostream>

using namespace std;

int bSearch_recur(int a[], int n, int x, int left, int right)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    
    if (a[mid] == x)
        return mid;
    else if(a[mid] < x)
        return bSearch_recur(a, n ,x, mid + 1, right);
    return bSearch_recur(a, n, x, left, mid - 1);
}

int main()
{
    int a[] = {1,3,5,6,8,10,12};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 3;

    cout << bSearch_recur(a, n, x, 0, n-1)  << "\n";

    return 0;
}