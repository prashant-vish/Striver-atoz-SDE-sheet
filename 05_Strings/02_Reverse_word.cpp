#include <bits/stdc++.h>
using namespace std;


// 
// time complexity O(n)
// space complexity O(1)
class Solution
{
public:
    string reverseWords(string s)
    {

        int n = s.size();
        string ans = "";
        string str = "";
        int i = n - 1;
        while (s[i] == ' ')
            i--;
        while (i >= 0)
        {
            if (s[i] == ' ')
            {
                reverse(str.begin(), str.end());
                ans += str;
                str = "";
            }
            else
            {
                str += s[i];
                if (ans.size() != 0 && str.size() == 1)
                {
                    ans += " ";
                }
            }
            i--;
        }
        reverse(str.begin(), str.end());
        ans += str;
        return ans;
    }
};