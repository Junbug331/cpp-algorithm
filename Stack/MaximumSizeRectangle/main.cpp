#include <iostream>
#include <stack>
#include <vector>
#include <memory>

using namespace std;

class Soluition
{
public:

    // n + n + n => O(n)
    int MaxRectInHisto(vector<int> &h)
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

        // Clear the stack memory to reuse the stack
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
        
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // when h[i] is minimum height
            if (Left[i] == -1 && Right[i] == -1)
                ans = max(ans, h[i] * n );
            
            //when there is no smaller element left of h[i] 
            else if (Left[i] == -1)
                ans = max(ans, h[i] * Right[i] );
            
            else if (Right[i] == -1)
                ans = max(ans, h[i] * (n - 1 - Left[i]) );
            else
                ans = max(ans, h[i] * (Right[i] - Left[i] - 1) );
        } 
        return ans;
    }

    int MaxRectInHisto(int h[], int n)
    {
        stack<int> st;
        auto left = unique_ptr<int[]>(new int[n+1]);
        auto right = unique_ptr<int[]>(new int[n+1]);
        
        for (int i = 0; i <= n; i++)
        {
            left[i] = -1;
            right[i] = -1;
        }

        for (int i = 1; i <= n; i ++)
        {
            while(!st.empty() && h[i] < h[st.top()])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n; i >= 1; i--)
        {
            while (!st.empty() && h[i] < h[st.top()])
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (left[i] == -1 && right[i] == -1)
                ans = max(ans, h[i] * n );
            else if (left[i] == -1)
                ans = max(ans, h[i] * (right[i] - 1));
            else if (right[i] == -1)
                ans = max(ans, h[i] * (n - 1 - left[i]));
            else
                ans = max(ans, h[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }

    int maxSizeRect()
    {
        int n, m, ans = 0;
        cin >> n >> m;
        int **a = new int*[n+1];
        int **t = new int*[n+1];

        // Inintialize a and t with 0
        for (int i = 0; i <= n; i++)
        {
            a[i] = new int[m+1];
            t[i] = new int[m+1];
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    a[i][j] = 0;
                else
                    cin >> a[i][j];
                t[i][j] = 0;
            }
        }

        // make t to be used in maxRectinHisto
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 0)
                    t[i][j] = 0;
                else
                    t[i][j] = 1 + t[i-1][j];
            }
        }

        for (int i = 1; i <= n; i++)
            ans = max(ans, MaxRectInHisto(t[i], m));

        return ans;
    }
};

int main()
{
    Soluition sol;
    
    //6,2,5,4,5,1,6
    cout << sol.maxSizeRect() << "\n";

    return 0;
}