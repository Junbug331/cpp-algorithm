#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// O(NlogN)
int ConnetRopes(vector<int> ropes)
{
    int ans = 0;
    priority_queue<int, vector<int>, greater<int> > pq;

    // O(NlogN)
    for (const auto &elem : ropes)
        pq.push(elem);
    
    while(!pq.empty())
    {
        int cost = 0;

        cost += pq.top();
        pq.pop();
        cost += pq.top();
        pq.pop();

        if (pq.empty())
            break;
        
        pq.push(cost);
    }

    return ans;
}

int main()
{
    vector<int> arr = {4, 3, 2, 6};
    cout << ConnetRopes(arr) << "\n";

    return 0;
}