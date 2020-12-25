#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::vector;
using std::string;
using std::cout;


vector<string> combination_(string str, vector<string>& comb)
{
    if (str.size() == 0)
    {
        comb.push_back("[]");
        return comb;
    }

    string firstEl(1, str[0]);
    string withoutFirst = str.substr(1, str.size()-1);

    ///  combination without first elem + (combination without first elem + first elem)
    ///  combination_(withoutFirst, comb)) will push all combinations without first element 
    ///  into global comb vector and return COPY of comb vector
    ///  After this function, comb will contain combinaions without first elem since we pass
    ///  the comb vector as reference

    for(auto elem : combination_(withoutFirst, comb))
    {
        if (elem == "[]")
            comb.push_back("[" + firstEl + "]");
        else
        {
            elem = elem.substr(1, elem.size() - 2);
            comb.push_back("[" + firstEl + elem +  "]");
        }       
    }
    
    return comb;
}

vector<string> combination(string str)
{
    vector<string> combs;
    combination_(str, combs);

    return combs;
}

int comb(int n, int k)
{
    if (k > n)
        throw std::invalid_argument("k can't exceed n");
    if (k == 0 || k == n)
        return 1;
    return comb(n-1, k-1) + comb(n-1, k);
}


/*
Generate All subset of Size K
n = 3
k = 2

[
    [1.2]
    [1,3]
    [2,3]
]

*/

void Combinations_(int offset, int n, int k, vector<int> partial, vector<vector<int>> &combinations)
{
    if (partial.size() == k)
    {
        combinations.push_back(partial);
        return;
    }

    int spaceLeft = k - partial.size();
    for (int i = offset; i <= n && spaceLeft <= n - i + 1; i++)
    {
        partial.push_back(i);
        Combinations_(i + 1, n, k, partial, combinations);
        partial.erase(partial.end() - 1 );
    }
}

vector<vector<int>> Combinations(int n, int k)
{
    vector<vector<int>> result;

    Combinations_(1, n, k, vector<int>(), result);

    return result;
}


int main()
{
    for (auto const& vec : Combinations(6, 3))
    {
        for (auto const& elem : vec)
        {
            cout << elem << " ";
        }
        cout << "\n";
    }

    return 0;
}