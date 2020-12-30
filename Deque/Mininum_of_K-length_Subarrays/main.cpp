#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    // O(n*k)
    vector<int> MinimumOfSubarrays_brute(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> result = {};
        for (int i = 0; i < n-k+1; i++)
        {
            int minVal = a[i];
            for (int j = i; j < i + 3; j++)  
                minVal = std::min(minVal, a[j]);
            
            result.push_back(minVal);
        }

        return result;
    }


    // O(n)
    vector<int> MinimumOfSubarrays_optimized(vector<int> &a, int k)
    {
        deque<int> dq;
        vector<int> ans;
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            while (!dq.empty() && a.at(dq.back()) > a[i])
                dq.pop_back();
            
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            
            dq.push_back(i);

            if (i >= k-1)
                ans.push_back(a.at(dq.front()));
        }
        return ans;
    }


private:

};

int main()
{
    vector<int> a {-7, 9, 2, 4, -1, 5, 6, 7, 1};
    int k = 3;
    Solution sol;

    for (auto const& elem : sol.MinimumOfSubarrays_optimized(a, k))
        cout << elem << " ";
    cout << "\n";

    return 0;
}