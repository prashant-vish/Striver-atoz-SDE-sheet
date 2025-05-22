#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string str)
    {
        int n = str.size();

        for (int i = 0; i < n / 2; i++)
        {
            if (str[i] != str[n - 1 - i])
            {
                return false;
            }
        }
        return true;
    }

    void findPartition(string str, vector<string> &ds, vector<vector<string>> &ans)
    {
        if (str.size() == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < str.size(); i++)
        {
            string supp = str.substr(0, i + 1);
            if (isPalindrome(supp))
            {
                ds.push_back(supp);
                findPartition(str.substr(i + 1), ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> supplement;
        vector<vector<string>> ans;
        findPartition(s, supplement, ans);
        return ans;
    }
};