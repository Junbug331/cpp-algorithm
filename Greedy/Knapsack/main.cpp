#include <iostream>
#include <algorithm>

using namespace std;

static const int Nmax = 10000;

struct obj
{
    int w;
    int vpw;
    bool operator < (const obj& x) const
    {
        return vpw > x.vpw;
    }
};

obj a[Nmax];

int main()
{
    int G, n;
    cin >> n >> G;
    
    for (int i = 1; i <= n; i++)
    {
        int v, w;
        cin >> v >> w;
        a[i].w = w;
        a[i].vpw = (double) v / w;
    }

    sort(a+1, a+n+1);

    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int g = min(a[i].w, G);
        ans += a[i].vpw * g;
        G -= g;
    }

    cout << ans << "\n";

    return 0;
}
