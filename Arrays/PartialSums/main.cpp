#include <iostream>
using namespace std;

void buildPartialSums(int *s, int a[], int n)
{
    s[1] = a[1];
    for (int i = 2; i < n; i++)
        s[i] = s[i-1] + a[i];
}

long long Query(int *s, int x, int y)
{
    cout << "s[i] ";
    for (int i=1; i < 9; i++)
        cout << s[i] << " ";
    cout << endl;
    cout << "s[y] = " << s[y] << " s[x-1] = " << s[x-1] << endl;
    return s[y] - s[x-1];
}

int main(int argc, char** argv)
{
    cout << "Testing Partial Sums on array" << endl;
    int a[9] = {0, 7, -2, 3, 9, -11, 5, 1, -3};
    int s[9];
    buildPartialSums(s, a, 9);
//    cout << "a[8] = {7, -2, 3, 9, -11, 5, 1, -3}" << endl;
//    cout << "Query(3, 6) = ";
    cout << Query(s, 3, 6) << endl;;

    return 0;
}