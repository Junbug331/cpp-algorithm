#include <iostream>
#include <utility>
#include <memory>

using namespace std;

void Merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k = 0;
    //unique_ptr<int[]> B(new int[high-low+1]);
    unique_ptr<int[]> B = make_unique<int[]>(10);

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else 
            B[k++] = A[j++];
    }
    while (i <= mid)
        B[k++] = A[i++];
    while (j <= high)
        B[k++] = A[j++];

    for (int i=0; i<k; i++)
        A[low+i] = B[i];

}

void MergeSort_iter(int A[], int n)
{
    int p, low, mid, high;

    for (p=2; p<=n; p=p*2)
    {
        for (int i=0; i+p-1<n; i=i+p)
        {
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            Merge(A,low, mid, high);
        }
    }
    if (p/2 < n)
        Merge(A,0,p/2-1,n-1);
}

void MergeSort_recur_(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low+high)/2;
        MergeSort_recur_(A,low,mid);
        MergeSort_recur_(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

void MergeSort_recur(int A[], int n)
{
    MergeSort_recur_(A, 0, n-1);
}


int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};

    int n = sizeof(A)/sizeof(A[0]);

    for (int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n"); 

    MergeSort_recur(A,n);

    for (int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n"); 

    return 0;
}