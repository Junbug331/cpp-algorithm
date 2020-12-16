#include <iostream>

const int NMAX = 100001;

int LongestConsecNumSubarray(int a[], int n)
{
    int ans = 0;
    int start = 0, end = 0;
    bool fr[NMAX] = {false};
    for (int left = 0; left < n; left++)
    {
        for (int i=0; i < n; i++)
            fr[i] = false;
        int min = a[left], max = a[left];
        for (int right = left; right < n; right++)
        {
            if (fr[a[right]])
                break;
            fr[a[right]] = true;
            min = min < a[right] ? min : a[right];
            max = max > a[right] ? max : a[right];

            if (right - left == max - min)
            {
                if (ans < (right - left + 1))
                {
                    ans = right - left + 1;
                    start = left;
                    end = right;
                }
            }       
        }
    }
    
    std::cout << "[" << start << ", " << end<< "] = " << ans << std::endl;
    for (int i = start; i <= end; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return ans;
}

int main()
{
    int a[] = {3, 7, 1, 4, 2, 5, 3, 8, 10, 9};
    int n = sizeof(a) / sizeof(a[0]);
    LongestConsecNumSubarray(a, n);
    return 0;
}