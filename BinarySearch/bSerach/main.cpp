#include <iostream>

using namespace std;

int bSearch(int a[], int n, int target)
{
    int left = 1, right = n, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == target)
            return mid;
        if (a[mid] < target)
            left = mid + 1;
        else
            right = mid  -1;
    }
    return -1;
}

int main()
{
    int a[] = {0, -1, 7, 13, 17, 19, 21 ,29, 43, 50, 63, 81, 103};
    int n = sizeof(a) / sizeof(a[0]);

    cout << bSearch(a, n, 17) << "\n";
    return 1;
}