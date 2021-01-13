#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unordered_set<ll> sll;

ll v[200005];

ll mod(int n, ll mod)
{
    return (((n % mod) * 1LL) + mod) % mod;
}

bool valid_shuffle(vector<int>& rooms)
{
    sll s;
    ll n = rooms.size();

    for (ll i=0; i < n; i++)
    {
        int new_idx = i + rooms[i];
        new_idx = mod(new_idx, n);

        if (s.find(new_idx) != s.end())
            return false;
        else
            s.insert(new_idx);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*
    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        for (ll i = 0; i < n; i++)
            cin >> v[i];
        
        sll s;

        ll flag = 0;
        for (ll i = 0; i < n; i++)
        {
            ll nxt_pos = i + v[i];
            nxt_pos = ((nxt_pos % n) + n) % n;

            if (s.find(nxt_pos) != s.end())
            {
                flag = 1;
                break;
            }
            s.insert(nxt_pos);
        }

        if (flag == 0)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    */

    vector<int> rooms = {-239, -2, -100, -3, -11};
    if (valid_shuffle(rooms))
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    
    return 0;
}