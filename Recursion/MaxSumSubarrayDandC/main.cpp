
/**
 * Maximum Sum of Subarray Divide and Conqure approach
 * 
 */
#include <iostream>

int MaxSumLeft(int a[], int mid, int left)
{
    int maxS = a[mid], sum = 0;
    for (int L = mid; L >= left; L--)
    {
        sum += a[L];
        maxS = std::max(maxS, sum);
    }
    return maxS;
}

int MaxSumRight(int a[], int mid, int right)
{
    int maxS = a[mid], sum = 0;
    for (int R = mid; R <= right; R++)
    {
        sum += a[R];
        maxS = std::max(maxS, sum);
    }
    return 0;
}

int MaxSumSubarray(int a[], int left, int right)
{
    if (left == right)
        return 0;
    
    int mid = (left + right) / 2;
    int ans = std::max(MaxSumSubarray(a, left, mid), MaxSumSubarray(a, mid+1, right));

    return std::max(ans, MaxSumLeft(a, mid, left) + MaxSumRight(a, mid+1, right));
}

int main()
{
    return 0;
}