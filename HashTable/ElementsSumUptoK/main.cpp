/*
Statement Given an array of N integers, find 6 of them,
which added together gives sum S. You can take an integer
any number of times

N = 5, nums = [3, -7, 2, -1, -10], S = 21
Answers : (3, 3, 7, 2, -1) etc

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

// O(N^5)
vector<int> ElementsSumUptoK_br_1st(vector<int> &arr, int S)
{
    vector<int> ans;
    unordered_map<int, int> myMap;

    for (const auto& elem : arr)
        myMap[elem]++;
    
    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(arr[i]);
        for (int j = 0; j < arr.size(); j++)
        {
            ans.push_back(arr[j]);
            for (int k = 0; k < arr.size(); k++)
            {
                ans.push_back(arr[k]);
                for (int l = 0; l < arr.size(); l++)
                {
                    ans.push_back(arr[l]);
                    for (int m = 0; m < arr.size(); m++)
                    {
                        ans.push_back(arr[m]);
                        int s = arr[i] + arr[j] + arr[k] + arr[l] + arr[m];
                        if (myMap.find(S - s) != myMap.end())
                        {
                            ans.push_back(S-s);
                            return ans;
                        }
                        ans.erase(ans.end()-1);
                    }
                    ans.erase(ans.end()-1);
                }
                ans.erase(ans.end()-1);
            }
            ans.erase(ans.end()-1);
        }
        ans.erase(ans.end()-1);
    }

    return ans;
}

// O(N^2 + N^4)  ==> O(N^4)   
vector<int> ElementsSumUptoK_br_2nd(vector<int> &arr, int S)
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, pair<int, int>> myMap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (myMap.find(i+j) == myMap.end())
                myMap.insert( make_pair(arr[i] + arr[j], make_pair(arr[i], arr[j]) ) );
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans.push_back(arr[i]);
        for(int j = 0; j < n; j++)
        {
            ans.push_back(arr[j]);
            for (int k = 0; k < n; k++)
            {
                ans.push_back(arr[k]);
                for(int l = 0; l < n; l++)
                {
                    ans.push_back(arr[l]);

                    int s = arr[i] + arr[j] + arr[k] + arr[l];
                    if (myMap.find(S-s) != myMap.end())
                    {
                        ans.push_back(myMap[S-s].first);
                        ans.push_back(myMap[S-s].second);
                        return ans;
                    }

                    ans.erase(ans.end()-1);
                }
                ans.erase(ans.end()-1);
            }
            ans.erase(ans.end()-1);
        }
        ans.erase(ans.end()-1);
    }

    return ans;
}

vector<int> recur_(vector<int> &arr, vector<int> ans, unordered_map<int, pair<int,int>>&map, int& S, int sum)
{
    if (ans.size() == 4)
    {
        if (map.find(S-sum) != map.end())
        {
            ans.push_back(map[S-sum].first);
            ans.push_back(map[S-sum].second);
       }
       return ans;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(arr[i]);
        ans = recur_(arr, ans, map, S, sum+arr[i]);
        if (ans.size() == 6)
            return ans;
        ans.erase(ans.end()-1);
    }
    
    return ans;
}

vector<int> ElementsSumUptoK_br_2nd_recur(vector<int> &arr, int S)
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, pair<int, int>> myMap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (myMap.find(i+j) == myMap.end())
                myMap.insert( make_pair(arr[i] + arr[j], make_pair(arr[i], arr[j]) ) );
        }
    }

    return recur_(arr, ans, myMap, S, 0);
}

//Optimized version O(N^3)
vector<int> ElementsSumUptoK_Optimized(vector<int> &arr, int S)
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, vector<int>> myMap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int sum = arr[i]+ arr[j] + arr[k];
                if (myMap.find(sum) == myMap.end())
                {
                    vector<int> tmp;
                    tmp.push_back(arr[i]);
                    tmp.push_back(arr[j]);
                    tmp.push_back(arr[k]);
                    myMap.insert(make_pair(sum, tmp));
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans.push_back(arr[i]);
        for (int j = 0; j < n; j++)
        {
            ans.push_back(arr[j]);
            for (int k = 0; k < n; k++)
            {
                ans.push_back(arr[k]);
                int s = arr[i] + arr[j] + arr[k];
                if (myMap.find(S-s) != myMap.end())
                {
                    ans.push_back(myMap[S-s][0]);
                    ans.push_back(myMap[S-s][1]);
                    ans.push_back(myMap[S-s][2]);

                    return ans;
                }
                ans.erase(ans.end()-1);
            }
            ans.erase(ans.end()-1);
        }
        ans.erase(ans.end()-1);
    }

    return ans;
}

// Recusive Approach of Optimized version
vector<int> ElementsSumUptoK_Optimized_recur_(vector<int> &arr, vector<int> ans, unordered_map<int, vector<int>> &map, int S, int sum)
{
    if (ans.size() == 3)
    {
        if (map.find(S-sum) != map.end())
        {
            ans.push_back(map[S-sum][0]);
            ans.push_back(map[S-sum][1]);
            ans.push_back(map[S-sum][2]);
        }
        return ans;
    }


    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(arr[i]);

        ans = ElementsSumUptoK_Optimized_recur_(arr, ans, map, S, sum+arr[i]);

        if (ans.size() == 6)
            return ans;

        ans.erase(ans.end()-1);
    }


    return ans;
}

vector<int> ElementsSumUptoK_Optimized_recur(vector<int> &arr, int S)
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, vector<int>> myMap;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                int sum = arr[i]+ arr[j] + arr[k];
                if (myMap.find(sum) == myMap.end())
                {
                    vector<int> tmp;
                    tmp.push_back(arr[i]);
                    tmp.push_back(arr[j]);
                    tmp.push_back(arr[k]);
                    myMap.insert(make_pair(sum, tmp));
                }
            }
        }
    }

    return ElementsSumUptoK_Optimized_recur_(arr, ans, myMap, S, 0);
}


/*
SOLUTION
*/

vector<int> FindSum(vector<int>& nums, int S)
{
    int n = nums.size();
    unordered_set<int> mySums;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                int sum1 =  nums[i] + nums[j] + nums[k];
                mySums.insert(sum1);

                if (mySums.find(S - sum1) != mySums.end())
                {
                    for (int i1 = 0; i1 < n; i1++)
                    {
                        for (int j1 = i1; j1 < n; j1++)
                        {
                            for (int k1= j1; k1 < n; k1++)
                            {
                                int sum2 = nums[i1] + nums[j1] + nums[k1];
                                if (sum2 == S - sum1)
                                    return {nums[i1], nums[j1], nums[k1], nums[i], nums[j], nums[k]};
                            }
                        }
                    }
                }
            }
        }
    }

    return {};
}

int main()
{
    vector<int> arr = {3, 7, 2, -1, -10};
    int S = 21;

    for (auto& elem : ElementsSumUptoK_Optimized(arr, 1))
        cout << elem << " ";
    cout << "\n";

    for (auto& elem : ElementsSumUptoK_Optimized(arr, S))
        cout << elem << " ";
    cout << "\n";

    for (auto& elem : FindSum(arr, S))
        cout << elem << " ";
    cout << "\n";

    return 0;
}