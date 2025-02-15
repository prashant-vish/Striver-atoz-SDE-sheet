#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(string &str1, int n, int i)
    {

        if (i >= (n / 2))
        {
            return true;
        }
        if (str1[i] != str1[n - 1 - i])
        {
            return false;
        }
        return solve(str1, n, i + 1);
    }
    bool isPalindrome(string s)
    {
        int n = s.length();
        string str = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                str += tolower(s[i]);
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                str = str + s[i];
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                str = str + s[i];
            }
        }
        n = str.length();
        cout << str;
        return solve(str, n, 0);
    }
};