#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    static unordered_map<char, char> m;

public:
    bool validParentheses(string parentheses)
    {   
        stack<char> st;
        for (auto const& c : parentheses)
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else
            {
                if (st.empty())
                    return false;
                if (m[st.top()] != c)
                    return false;
                st.pop();   
            }
        }
        return st.empty();
    }
};

unordered_map<char,char> Solution::m = 
{
    {'(', ')'},
    {'{', '}'},
    {'[', ']'}
};

int main()
{
    Solution obj;

    if (obj.validParentheses("[[(){}]])")) 
        cout << "valid\n";
    else
        cout <<"invalid\n";


    return 0;   
}