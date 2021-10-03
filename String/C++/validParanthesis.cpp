// Program to check if an input string has valid paranthesis

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> mp = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for (char c : s)
        {
            if (mp.find(c) != mp.end())
            {
                st.push(c);
            }
            else if (!st.empty() && mp[st.top()] == c)
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid("{[]}") << endl;
    cout << s.isValid("") << endl;
    cout << s.isValid("(") << endl;
    cout << s.isValid("[") << endl;
    cout << s.isValid("{") << endl;
    return 0;
}
