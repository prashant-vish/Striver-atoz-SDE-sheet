#include <bits/stdc++.h>
using namespace std;

// Time complexity -O(n*min(strs[i].size()))
// space complexity-O(1)

class Solution
{
public:
    bool check(vector<string> &strs, char ch, int i)
    {
        for (int j = 0; j < strs.size(); j++)
        {
            if (ch != strs[j][i])
            {
                return false;
            }
        }
        return true;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        string temp;
        int min_size = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i].size() <= min_size)
            {
                temp = strs[i];
                min_size = strs[i].size();
            }
        }
        if (!temp.size())
            return "";
        string ans = "";
        for (int i = 0; i < min_size; i++)
        {
            char ch = temp[i];
            if (check(strs, ch, i))
            {
                ans += ch;
            }
            else
            {
                return ans;
            }
        }
        return ans;
    }
};