#include <iostream>
#include <utility>

using namespace std;

void SelectionSort(int A[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        int k=i;
        for (int j=i; j<n; j++)
        {
            if (A[j]<A[k])
                k = j;
        }
        swap(A[i], A[k]);
    }
}

int main()
{
    int A[] = {3,7,9,24, 10,6,5,12,4,11,2,13};
    int n = sizeof(A)/sizeof(A[0]);
        
    SelectionSort(A,n);

    for (int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}