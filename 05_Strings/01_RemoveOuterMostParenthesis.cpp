#include <bits/stdc++.h>
using namespace std;

// Time Complexity -O(n)
// Space Complexity -O(1)

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = s.size();
        int count = 0;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                if (count > 0)
                {
                    ans += s[i];
                }
                count++;
            }
            else
            {
                count--;
                if (count > 0)
                {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};