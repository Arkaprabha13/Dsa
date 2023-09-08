#include <bits/stdc++.h>
using namespace std;
int postfix_evaluation(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int operand_2 = st.top();
            st.pop();
            int operand_1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(operand_1 + operand_2);
                break;
            case '-':
                st.push(operand_1 - operand_2);
                break;
            case '*':
                st.push(operand_1 * operand_2);
                break;
            case '/':
                st.push(operand_1 / operand_2);
                break;
            case '^':
                st.push(pow(operand_1, operand_2));
                break;

            default:
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    cout << postfix_evaluation("46+2/5*7+");
    return 0;
}