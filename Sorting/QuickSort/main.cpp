#include <iostream>
#include <utility>

using namespace std;

int Partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i=l, j=h;

    do
    {
        do{i++;} while(A[i]<=pivot);
        do{j--;} while(A[j]>pivot);
        if (i<j) swap(A[i],A[j]); 
    } while (i<j);
    swap(A[l], A[j]);

    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l<h)
    {
        j = Partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main()
{
    int A[] = {3,7,9,24,10,6,5,12,4,11,2,13, INT32_MAX};
    int n = sizeof(A)/sizeof(A[0]);
    
    QuickSort(A, 0, n-1);

    for (int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}