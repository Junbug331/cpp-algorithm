#include <iostream>

const static int NMAX = 10000;
int fr[NMAX];

int slidingWindow(int a[], int n, int k)
{
    int ans = 0, cnt = 0, Right;
    
    // First Loop to find maxR(index_1)
    for (Right = 1; Right <= n; Right++)
    {
        if(++fr[a[Right]] == 1)
            cnt++;
        if(cnt > k)
            break;
    }

    // If entir array is valid
    if (cnt <= k)
        return n;
        
    /// If not, reset the maxR(index_1) to correct position
    /// 1 2 3 4 5, k = 3
    /// 1). fr[a[Right]] -= 1
    /// 2). Right -= 1
    if (--fr[a[Right--]] == 0)
        cnt--;
    
    ans = Right;

    // Second Loop from (index_2 to index_n)
    for (int Left = 2; Left <= n; Left++)
    {
        /// del a[Left - 1] from fr
        /// if deleted element was a distinct num, decremeant counter
        if (--fr[a[Left -1]] == 0)
            cnt--;

        while (Right < n)
        {
            /// 1. Right += 1;
            /// 2. fr[a[Right]] += 1
            if (++fr[a[++Right]] == 1)
                cnt++;
            if (cnt > k)
                break;
        }
        // if Right = n, meanig while loop didn't enter break condition
        if (cnt <= k)
            return std::max(ans, n - Left + 1);
        
        if ( --fr[a[Right--]] == 0)
            cnt--;

        ans = std::max(ans, Right-Left+1);
    }

    return ans;
}

int slidingWindow_repeat(int a[], int n, int k)
{
    int ans = 0, cnt = 0, right;
    for (right = 0; right < n; right++)
    {
        if (++fr[a[right]] == 1)
            cnt++;
        if (cnt > k)
            break;
    }
    if (cnt <= k)
        return n;
    if (--fr[a[right--]] == 0)
        cnt--;


    for(int left = 2; left < n; left++)
    {
        if (--fr[a[left - 1]] == 0)
            cnt--;
        while (right < n-1)
        {
            if( ++fr[a[++right]] == 1)
                cnt++;
            if (cnt > k)
                break;
        }
        if (cnt <= k)
            return ans > (right - left + 1) ? ans : (right - left + 1);

        if (--fr[a[right--]] == 0)
            cnt--;
        ans = ans > (right - left + 1) ? ans : (right - left + 1);
    }
    return ans;
}

int main()
{
    int a[] = {1, 5, 2, 1, 7, 2, 1, 5, 5, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;

    SlidingWinodw(a, n, k);

    return 0;
}