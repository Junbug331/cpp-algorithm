#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int MinPlatform(vector<pair<double, double>> trains)
{
    vector<pair<double,int>> events;
    
    for (auto const& tr : trains)
    {
        events.push_back(make_pair(tr.first, 1));
        events.push_back(make_pair(tr.second, 0));
    }
    sort(events.begin(), events.end());
    
    int ans = 0, freePlat = 0;
    for (const auto& ev : events)
    {
        if (ev.second == 0)
            freePlat++;
        else
        {
            if (freePlat == 0)
                ans++;
            else
                freePlat--;
        }
    }

    return ans;
}

int main()
{
    vector<pair<double, double>> trains =
        {
            make_pair(2, 2.30),
            make_pair(2.10, 3.40),
            make_pair(3.00, 3.20),
            make_pair(3.20, 4.30),
            make_pair(3.50, 4),
            make_pair(5, 5.20)
        };
    
    cout << MinPlatform(trains) << "\n"; 

    return 0;
}