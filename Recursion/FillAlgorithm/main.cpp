#include <iostream>

using namespace std;

const int Nmax = 1005;

char a[Nmax][Nmax];
bool vis[Nmax][Nmax];

const static int dx[4] = {-1, 0, 1, 0};
const static int dy[4] = {0, 1, 0, -1};

bool isValid(int row, int col, int n, int m)
{
    if(row  < 1 || row > n || col < 1 || col > m)
        return false;
    if (a[row][col] == '#' || vis[row][col])
        return false;
    return true;
}

// Depth First Approach
void fillAlgo(int row, int col , int& cellCnt, int n, int m) 
{
    cellCnt++;
    vis[row][col] = true;
    for(int i = 0; i < 4; i++)
    {
        if(isValid(row,col,n, m))
            fillAlgo(row+dx[i], col+dy[i], cellCnt, n, m);
    }
}

int main()
{
    int n, m;
    int islandCnt = 0;
    int maxCellCnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(isValid(i, j, n, m))
            {
                islandCnt++;
                int cellCnt = 0;
                fillAlgo(i ,j, cellCnt, n, m);
                maxCellCnt = max(maxCellCnt, cellCnt);
            }
        }
    }

    cout << islandCnt << " " << maxCellCnt << "\n";
    return 0;
}