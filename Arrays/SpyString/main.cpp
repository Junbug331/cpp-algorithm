#include <iostream>

typedef long long ll;


// n -> number of strings
// m -> length of each string
ll n, m;
char a[100][100];
char final_string[100];

bool isok()
{
    for (ll i = 2; i <= n; i++)
    {
        ll c = 0;
        for(ll j = 1; j <= m; j++)
        {
            if (final_string[j] != a[i][j])
                c++;
        }
        if (c > 1)
            return false;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    ll t;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n >> m;

        for (ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                std::cin >> a[i][j];
            }
        }

        for (ll j = 1; j <= m; j++)
        {
            final_string[j] = a[1][j];
        }

        ll flag = 0;
        for (ll i = 1; i <= m; i++)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                final_string[i] = c;
                if (isok())
                {
                    for (ll i=1; i <= m; i++)
                    {
                        std::cout << final_string[i];
                    }
                    std::cout << '\n';
                    flag = 1;
                    break;
                }
            }
        }
    }

    return 0;
}