/*
Given a list of items with values and weights,
as well as a max weight, find the maximum value 
you can generate from items where the sum of the 
weights is less then the max

eg.

weights = {10, 20 ,30}
values = {60, 100, 120}
max weight = 50
*/

#include <iostream>
#include <vector>

using namespace std;



//Recursive apporach O(2^n) --> Combination
int knapsack_recur(int i, int W, vector<int> weights, vector<int> vals)
{
    if (i == weights.size())
        return 0;
    
    // If the item at current index has more weight than the max
    if (W - weights[i] < 0)
        return knapsack_recur(i + 1, W, weights, vals);
    
    // Otherwise,
    // try when the item is included and when the item is excluded
    return max(
            knapsack_recur(i + 1, W, weights, vals), // excluding current item
            knapsack_recur(i + 1, W - weights[i], weights, vals) + vals[i] // includeing current item
            );   
}

int knapsack_brute(int W, vector<int> weights, vector<int> vals)
{
    return knapsack_recur(0, W, weights, vals);
}

/*

Optimized Approach O(n * m)
Requirement for Dynamic Apporoach
    Optimal sub structure
    overlapping sub problem

weights = {10, 20 ,30}
values = {60, 100, 120}
max weight = 50

row : maxWeight
col : item weight
[row][col] = value

cache[row][col]
   0   1    2    3    4    5
0 [0,  0,   0,   0,   0,   0]
1 [0,  6,   6,   6,   6,   6]
2 [0,  6,  10,  16,  16,  16]
3 [0,  6,  10,  16,  18,  22]

when current item's weight is bigger than the max weight
if weight[row-1] > col
    cache[row][col] = cache[row-1][col]
else
    max()

*/

int knapsack_dynamic(int W, vector<int> weights, vector<int> vals)
{
    vector< vector<int> > cache (weights.size()+1, vector<int> (W+1, 0));
    int i, j;

    for (i = 1; i <= weights.size(); i++)
    {
        for (j = 1; j <= W; j++)
        {
            // if it's too big
            if (weights[i-1] > j)
            {
                cache[i][j] = cache[i-1][j];
                cout.width(3);
                cout << cache[i][j] << " ";
            }
                
            else
            {
                cache[i][j] = max(
                    cache[i-1][j],
                    cache[i-1][j - weights[i-1]] + vals[i-1]);
                cout.width(3);
                cout << cache[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return cache[i-1][j-1];
}

int main()
{
    vector<int> weights = {1, 2, 3, 5, 9, 10};
    vector<int> values = {6, 10, 12, 18, 24};
    int maxWeight = 20;

    cout << knapsack_brute(maxWeight, weights, values) << "\n";
    cout << knapsack_dynamic(maxWeight, weights, values) << "\n";
    cout << "\n";
    cout << knapsack_brute(maxWeight, weights, values) << "\n";

    return 0;
}