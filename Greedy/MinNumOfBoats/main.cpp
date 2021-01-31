#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;


int MinNumOfBoats(int maxW, int B, vector<int> weights)
{
    int ans = 0;
    int i = 0;

    sort(weights.begin(), weights.end());
    while (i < weights.size())
    {
        if (i+1 < weights.size() && weights[i] + weights[i+1] <= maxW && weights[i+1] - weights[i] <= B )
        {
            cout << "pair: " << weights[i] << " " << weights[i+1] << "\n"; 
            ans++;
            i += 2;
            continue;
        }
        cout << "single: " << weights[i] << "\n";
        ans++;
        i++;
    }

    return ans;
}

// Solution
int solve(vector<int> vec, int w, int b)
{
    // sort the array
    sort(vec.begin(), vec.end());
    int n = vec.size(), ans = 0;
    
    // Frequency array
    vector<bool> isTaken(n, false);

    // heap of pair(weight, its index)
    priority_queue<pair<int,int>> pq;
    
    int p = 0;

    for (int i = n-1; i >= 0; i--)
    {
        while (p<i && vec[p]+vec[i] <= w)
            pq.push({vec[p], p++});
        if(isTaken[i]) continue;
        while (!pq.empty() && vec[i]-pq.top().first <= b)
        {
            if (isTaken[pq.top().second] || pq.top().second == i)
            {
                pq.pop();
                continue;
            }
            isTaken[i] = isTaken[pq.top().second] = true;
            pq.pop();
            break;
        }
        ans++;
    }
    return ans;
}

int main()
{
    vector<int> weights = {81, 37, 32, 88, 55, 93, 45, 72};
    int B = 10;
    int W = 100;

    cout << MinNumOfBoats(W,B, weights) << "\n";
    cout << solve(weights, W, B) << "\n";
    return 0;
}