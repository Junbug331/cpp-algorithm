/*


a   = [7, 3, 2, 6, 11, 9, 8, 10, 13]
index  0  1  2  3  4   5  6  7   8
ans = [4, 0, 3, 4, 8,  7, 7  8,  -1]


*/

#include <iostream>
#include <stack>

using namespace std;

const int Nmax = 100005;

class Solution
{
public: 
    void FirstGreaterElement(int a[], int n, int* ans)
    {
        stack<int> st;
        for(int i = 1; i <= n; i++)
        {
            while(!st.empty() && a[st.top()] < a[i] )
            {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
};

int main()
{
    int a[Nmax], ans[Nmax], n;
    Solution obj;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    obj.FirstGreaterElement(a, n, ans);

    for(int i = 1; i <=n; i++)
        cout << ans[i] << " ";

    cout << "\n";

    return 0;
}