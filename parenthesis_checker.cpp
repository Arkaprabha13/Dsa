#include <bits/stdc++.h>
using namespace std;
bool is_valid(string s)
{
    int n = s.length();
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (!st.empty() && s[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (!st.empty() && s[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return ans;
}
int main()
{
    string s; //="{[()]}";
    cin >> s;
    if (is_valid(s))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "not validd " << endl;
    }
    return 0;
}