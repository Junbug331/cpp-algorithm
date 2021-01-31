#include <iostream>
#include <memory>

using namespace std;

int findMax(int A[], int n)
{
    int max = INT32_MIN;
    for (int i=0; i<n; i++)
        max = (max >= A[i]) ? max : A[i];
    return max;
}

void CountSort(int A[], int n)
{
    int max = findMax(A, n);
    int k=0;
    max++;
    unique_ptr<int[]> C = unique_ptr<int[]>(new int[max]);
    
    for (int i=0; i<n; i++)
        C[A[i]]++;
    
    for (int i=0; i<max; i++)
    {
        if (C[i] > 0)
            for (int j=1; j<=C[i]; j++)
                A[k++] = i;
    }
}

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n = sizeof(A)/sizeof(A[0]);
    
    CountSort(A, n);
    for (int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}