#include <iostream>
#include <utility>

using namespace std;

void InsertionSort(int A[], int n)
{
    for (int i=1; i<n; i++)
    {
        int j = i-1;
        int x = A[i];
        while (j>-1 && A[j]>x)
        {
            A[j+1] = A[j];
            j--;

        }
        A[j+1] = x;
    }
}

int main()
{
    int A[] = {3,7,9,10,6,5,12,4,11,2};
    int n = sizeof(A)/sizeof(A[0]);
        
    InsertionSort(A,n);

    for (int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}