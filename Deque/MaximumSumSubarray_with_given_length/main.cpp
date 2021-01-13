#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSum(int a[], int n, int A, int B)
    {
        deque<int> dq;
        vector<int> input(n+1, 0);
        vector<int> s(n+1, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
            input[i+1] = a[i];
        
        for (int i = 1; i <= n; i++)
            s[i] = s[i-1] + input[i];
        
        dq.push_back(0);

        int tmp = 0; // For Right - A range 

        for (int Right = 1; Right <= n; Right++)
        {
            // Delete outdated element
            if (!dq.empty() && dq.front() < Right-B)
                dq.pop_front();
            
            // Minimum number of subarray length
            if (Right >= A)
            {
                if (dq.front() <= Right - A )
                {   
                    ans = std::max(ans, s[Right] - s[dq.front()]);
                    cout << "Right = " << Right << ", L` = " << dq.front() << "\n";

                }
                else
                {
                    ans = std::max(ans, s[Right] - s[tmp]);
                    cout << "Right = " << Right << ", L` = " << tmp << "\n";
                } 
            }
                
            // Sort the deque increasingly
            while(!dq.empty() && s[dq.back()] >= s[Right])
            {
                tmp = dq.back();
                //cout << "tmp = " << tmp << "\n";
                dq.pop_back();
            }

            dq.push_back(Right);
        }

        return ans;
    }
};

int main()
{
    int a[] = {2, -9, 7, -2, 8, -1, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int A = 2, B = 4;

    Solution sol;
    cout << sol.maxSum(a, n, A, B) << "\n";

    return 0;
}