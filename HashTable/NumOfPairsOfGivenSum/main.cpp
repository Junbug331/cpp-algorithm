#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::vector;
using std::unordered_map;

/*
a = [3 -2  9  3 -2  4  9]
um (4, 2) (9, 1) (9, 2) 
*/

int NumOfPairs(vector<int> &arr, int S)
{
    int ans = 0;
    unordered_map<int,int> um;

    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] < 4)
        {
            if (um.find(S-arr[j]) == um.end())
                um.insert(std::make_pair(S-arr[j], 1));
            else
                um[S-arr[j]]++;
        }
    }
    unordered_map<int, int>::iterator it;
    for (int j = 0; j < arr.size(); j++)
    {
        if (um.find(arr[j]) != um.end())
            ans += um[arr[j]];
    }

    return ans;
}

int NumOfPairs_simple(vector<int>& arr, int S)
{
    int ans = 0;
    unordered_map<int, int> myMap;
    for (int j = 0; j < arr.size(); j++)
    {
        ans += myMap[S-arr[j]];
        myMap[arr[j]]++;
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 9, 9, -2, 3, -2, 4};
    int S = 7;
    cout << NumOfPairs(arr, S) << "\n";

    return 0;
}