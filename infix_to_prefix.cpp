#include <bits/stdc++.h>
using namespace std;
int precedence_checker(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1; // open bracket in the stack
}
string infix_to_prefix(string s)
{
    reverse(s.begin(), s.end());

    stack<char> st;
    string converted_to_infix;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            converted_to_infix += s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                converted_to_infix += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedence_checker(st.top()) >= precedence_checker(s[i]))
            {
                converted_to_infix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        converted_to_infix += st.top();
        st.pop();
    }
    reverse(converted_to_infix.begin(), converted_to_infix.end());
    return converted_to_infix;
}
int main()
{
    cout << infix_to_prefix("(a-b/c)*(a/k-l)");
    return 0;
}