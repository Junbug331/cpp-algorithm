#include <iostream>

long long MaximumSumSubArray(int a[], int n)
{
    int start, end, tmp_end;
    long long max, tmp_max;
    start = end = max = tmp_max = tmp_end = 0;

    for (int i=0; i<n; i++)
    {
        if (max + a[i] < max)
        {
            tmp_max = max;
            tmp_end = i - 1;
        }

        max += a[i];
        end = i;

        if (a[i] >= max)
        {
            start = i;
            end = i;
            max = a[i];
        }

    }

    if ( tmp_max > max)
    {
        max = tmp_max;
        end = tmp_end;
    }

    std::cout << "[" << start << ", " << end <<"]" << " = " << max << std::endl;

    return max;
}

long long MaxSumSubArray_Greedy(int a[], int n)
{
    long long sum = 0, ans = a[0];
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (sum > ans)
        {
            ans = sum;
            end = i;
        }
            

        if (sum <= 0)
        {
            sum = 0;
            if (i+1 < n)
                start = i + 1;
        }
            
        //std::cout << sum << std::endl;
    }
    std::cout << "[" << start << ", " << end << "] = " << ans << std::endl;
    return ans;
}

int maxSumSubArray_partialSum(int a[], int n)
{
    int s[n], ans = a[0], minSubArrSum = 0;
    int start = 0, end = 0;
    s[0] = a[0];

    // Making a partial Sub Sum Array
    for (int i=1; i<n; i++)
        s[i] = s[i-1] + a[i];

    for (int i=0; i<n; i++)
    {
        if (s[i]-minSubArrSum > ans)
        {
            ans = s[i] - minSubArrSum;
            end = i;
        }
        if (s[i] <= minSubArrSum)
        {
            minSubArrSum = s[i];
            start = i + 1; 
        }
    }
    
    std::cout << "[" << start << ", " << end << "] = " << ans << std::endl;
  
    return ans; 
}

int main()
{
    //int a[] = {5, -6, 3, 4, -2, 3, -3};
    int a[] = {-5, 3, -3, 5, -3, 6, -2, -3, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    std::cout << MaxSumSubArray_Greedy(a, n) << std::endl;
    std::cout << maxSumSubArray_partialSum(a, n) << std::endl;

    return 0;
}