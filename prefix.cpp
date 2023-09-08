#include <bits/stdc++.h>
using namespace std;
int prefix_evaluation(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int operand_1 = st.top();
            st.pop();
            int operand_2 = st.top();
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
    int ans = prefix_evaluation("-+7*45+20");
    cout << ans;

    /*
        -+7*45+20     <-start from end
        -+7*45(2+0)
        -+7(4*5)(2)
        -(7+20)(2)
        27-2
        =25
    */
    return 0;
}