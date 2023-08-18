#include <bits/stdc++.h>
using namespace std;
bool anagram(string &s1, string &s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1 == s2);
}
const int CHAR = 256;
bool areAnagram(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    if (n1 != n2)
        return false;

    int count[CHAR] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < CHAR; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    string s1, s2;
    cout << "Enter two strings -> ";
    cin >> s1 >> s2;
    if (anagram(s1, s2))
    {
        cout << "anagram" << endl;
    }
    else
    {
        cout << "non anagram" << endl;
    }
    return 0;
}