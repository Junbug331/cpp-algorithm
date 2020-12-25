/*
eg. substring("ABAB", "BABA") = "ABA"
   A  B  A  A
B [0, 1, 1, 1]
A [1, 0, 2, 0]
B [0, ]
A []


Recursive sub Problem
lcs("aab", "azb")
       ^      ^     => smae character
    1 + lcs("aa", "az")
              ^     ^   => diff character
        max(lcs("a", "az"), lcs("aa", "a"))


*/
#include <memory>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Recursive Apporaceh O(2^n)
int lcs_recur(string s1, string s2)
{
    if (s1.size() == 0 || s2.size() == 0)
        return 0;
    if (s1[s1.size()-1] == s2[s2.size()-1])
        return 1 + lcs_recur(s1.substr(0, s1.size()-1), s2.substr(0,s2.size()-1));

    return max(lcs_recur(s1.substr(0,s1.size()-1), s2), lcs_recur(s1, s2.substr(0,s2.size()-1)));
}

/*
    "" A  G  G  T  A  B
"" [0  0  0  0  0  0  0]
G  [0  0  1  1  1  1  1]
X  [0  0  1  1  1  1  1]
T  [0  0  1  1  2  2  2]
X  [0  0  1  1  2  2  2]
A  [0  1  1  1  1  3  3]
Y  [0  1  1  1  1  3  3]
B  [0  1  1  1  1  3  4]

O(n*m)

*/
int lcs_DP(string s1, string s2)
{
    int **cache = new int*[s1.size()+1];
    for (int i = 0; i < s1.size()+1; i++)
        cache[i] = new int[s2.size()+1];

    for (int s1row = 0; s1row <= s1.size(); s1row++)
    {
        for (int s2col = 0; s2col <= s2.size(); s2col++)
        {
            if (s1row == 0 || s2col == 0)
                cache[s1row][s2col] = 0;
            else if (s1[s1row-1] == s2[s2col-1])
            {
                cache[s1row][s2col] = 1 + cache[s1row-1][s2col-1];
                cout.width(3);
                cout << cache[s1row][s2col] << " ";
            }
            else
            {
                cache[s1row][s2col] = max(cache[s1row-1][s2col], cache[s1row][s2col-1]);
                cout.width(3);
                cout << cache[s1row][s2col] << " ";
            }  
        }
        cout << "\n";
    }
    int ans = cache[s1.size()][s2.size()]; 

    for (int i = 0; i < s2.size()+1; i++)
        delete[] cache[i];
    delete[] cache;

    return ans;
}

int main()
{
    cout << lcs_recur("GXTXAYB", "AGGTAB") << "\n";
    cout << lcs_DP("GXTXAYB", "AGGTAB") << "\n";

    unique_ptr<int*[]> cache(new int*[5]);
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        unique_ptr<int[]> cache_i(new int[5]);
        for (int j = 0; j < 5; j++)
            cache_i[j] = cnt+j;
        
        
    }

    return 0;
}

