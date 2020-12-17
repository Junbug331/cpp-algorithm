#include <iostream>

using namespace std;

const int Nmax= 1001;
bool a[Nmax][Nmax];
int n, m, maxLen[Nmax][Nmax];
/// maxLen[i][j] = max Number Lets call it as x, 
/// such as From (i-x+1, j-x+1) UpperLeft corner to (i,j) LowerRight corner
/// is full 1s
/// maxLen[i][j] = 
///     if (a[i][j] == 1)
///         min(maxLen[i-1][j], maxLen[i][j-1], maxLen[i-1][j-1])
///     otherwise 0.

int MaxSquareSize(bool a[][Nmax], int n, int m)
{
    int ans = 0;
    //Compute maxLen
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= m; c++)
        {
            if (a[r][c] == false)
                maxLen[r][c] = 0;
            else
                maxLen[r][c] = 1 + min(min(maxLen[r-1][c], maxLen[r][c-1]), maxLen[r-1][c-1]);
            //ans = ans > maxLen[r][c] ? ans : maxLen[r][c];
            ans = max(ans, maxLen[r][c]);
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    cout << MaxSquareSize(a, n, m) << "\n";
    return 0;
}

