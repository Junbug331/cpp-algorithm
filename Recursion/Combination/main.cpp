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

int main()
{
    string str = "abcd";
    for (auto elem : combination(str))
        cout << elem << "\n";
    cout << "\n";

    return 0;
}