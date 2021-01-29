#include <iostream>
#include <algorithm>

using namespace std;

const static int Nmax = 10000;

struct Activity
{
    int start, finish;
    bool operator < (const Activity& x) const
    {
        return finish < x.finish;
    }
};
Activity act[Nmax];

int main()
{
    int n;
    cin >> n;

    for (int i=1; i<=1; i++)
    {
        cin >> act[i].start;
        cin >> act[i].finish;
    }

    sort(act+1, act+n+1);

    int ans = 0, prevFinish = -1;

    for (int i=1; i<=n; i++)
    {
        if (act[i].start > prevFinish)
        {
            ans++;
            prevFinish = act[i].finish;
        }
    }

    cout << ans << "\n";

    return 0;
}