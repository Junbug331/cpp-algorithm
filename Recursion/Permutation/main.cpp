/*

Write a function that returns all permutations of a given list
eg.

permutation({1, 2, 3})
{1, 2, 3}
{1, 3, 2}
{2, 1, 3}
{2, 3, 1}
{3, 1, 2}
{3, 2, 1}

permutations("abc")

"abc"
"acb"
"bac"
...

prefix = ""
suffix = "abc"  ( decision space)

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Int Array

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void _permutations_backtrack(vector<int> arr, vector<vector<int>>& results, int index)
{
    if (index == arr.size())
        results.push_back(arr);

    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        _permutations_backtrack(arr, results, index + 1);
        swap(arr[i], arr[index]);
    }
}

vector<vector<int> >permutations_backtrack(vector<int> arr)
{
    vector<vector<int>> results;
    _permutations_backtrack(arr, results, 0);

    return results;
}

// String
void _permutations(string prefix, string suffix, vector<string> &results)
{
    if (suffix.length() == 0)
        results.push_back(prefix);
    else
    {
        for (int i = 0; i < suffix.length(); i++)
        {
            _permutations(
                prefix + string(1, suffix[i]), 
                suffix.substr(0,i) + suffix.substr(i+1, suffix.size()), 
                results);
        }
    }
}

vector<string> permutations(string s)
{
    vector<string> results;
    if (s.size() == 1)
    {
        results.push_back(s);
        return results;
    }
    else
    {
        _permutations("", s, results);
        return results;
    }
    
}


// Taking care of dupicate letters
void permuteUtil(string str, vector<int> count, int len, string& permu, vector<string> &result, int level)
{
    if (level == len)
    {
        result.push_back(permu);
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (count[i] == 0)
            continue;
        permu[level] = str[i];
        
        // Backtracing
        count[i]--;
        permuteUtil(str, count, len, permu, result, level+1);
        count[i]++;
    }
}

vector<string> permute(string input)
{
    // Inintializing an ordered map 
    map<char, int> countMap;
    for (char &c : input)
    {
        if (countMap.find(c) == countMap.end())
            countMap.insert(make_pair(c, 1));
        else
            ++countMap[c];
    }
    
    string str = "";
    vector<int>count;

    for (auto const& entry : countMap)
    {
        str += string(1, entry.first);
        count.push_back(entry.second);
    }

    // global variable for this function scope 
    // This two variable will be passed as reference
    vector<string> results;
    string permu(input.size(), ' ');

    permuteUtil(str, count, input.length(), permu, results, 0);

    return results;
}

int main()
{
    string input = "AABC";

    for(auto const& str : permute(input))
        cout << str << "\n";
    cout << "\n";

    return 0;
}