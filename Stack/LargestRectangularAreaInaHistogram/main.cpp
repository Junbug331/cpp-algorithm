#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Soluition
{
public:
    // O(n^2)
    int LargestRecAreaInaHis_brute(int a[], int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int minVal = a[i];
            for (int j = i; j < n; j++)
            {
                minVal = min(minVal, a[j]);
                int area = (j - i + 1 ) * minVal;
                ans = max(area, ans);
            }
        }
        return ans;
    }

    // n + n + n => O(n)
    long long LargestRecAreaInaHist_optimized(vector<int> &h)
    {
        int n = h.size();
        vector<int> Left(n, -1), Right(n, -1);
        stack<int> st;

        for (int i = 0; i <  n; i++)
        {
            while (!st.empty() && h[i] < h[st.top()])
            {
                Right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        
        for (int i = n-1; i >= 0; i-- )
        {
            while(!st.empty() && h[i] < h[st.top()])
            {
                Left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while  (!st.empty())
            st.pop();
        
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            // when h[i] is minimum height
            if (Left[i] == -1 && Right[i] == -1)
            {
                ans = max(ans, h[i] * n * 1LL);
                cout << "Area when h[" << i <<"] = " << h[i] << " is " << h[i] * n * 1LL << "\n"; 
            }
            //when there is no smaller element left of h[i] 
            else if (Left[i] == -1)
            {
                ans = max(ans, h[i] * (Right[i] - i) * 1LL);
                cout << "Area when h[" << i <<"] = " << h[i] << " is " << h[i] * (Right[i] - i) * 1LL << "\n";
            }
            else if (Right[i] == -1)
            {
                ans = max(ans, h[i] * (n - 1 - Left[i]) * 1LL);
                cout << "Area when h[" << i <<"] = " << h[i] << " is " << h[i] * (n - 1 - Left[i]) * 1LL << "\n";
            }
            else
            {
                ans = max(ans, h[i] * (Right[i] - Left[i] - 1) * 1LL);
                cout << "Area when h[" << i <<"] = " << h[i] << " is " << h[i] * (Right[i] - Left[i] - 1) * 1LL << "\n";
            }
              
        }
            
        return ans;
    }
};

int main()
{
    Soluition sol;
    
    int a[] = {6,2,5,4,5,1,6};
    int n = sizeof(a) / sizeof(a[0]);
    
    vector<int> a_vec{6,2,5,4,5,1,6};

    cout << sol.LargestRecAreaInaHis_brute(a, n) << "\n"; 
    cout << sol.LargestRecAreaInaHist_optimized(a_vec) << "\n";

    return 0;
}