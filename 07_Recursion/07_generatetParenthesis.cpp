#include <bits/stdc++.h>
using namespace std;

// brute force
// time complexity - O(n*2^2n)
// space complexity O(2n) stack space;

class Solution
{
public:
    bool isValid(string s)
    {
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count < 0)
            {
                return 0;
            }
        }
        return count == 0;
    }
    void solve(int n, string res, vector<string> &result)
    {
        if (res.size() == 2 * n)
        {
            if (isValid(res))
            {
                result.push_back(res);
            }
            return;
        }
        solve(n, res + '(', result);
        solve(n, res + ')', result);
    }

    vector<string> generateParenthesis(int n)
    {

        vector<string> result;

        solve(n, "", result);
        return result;
    }
};

// optimal Solution
// time complexity - O(2^2n)
// space complexity - O(2*n)

class Solution
{
public:
    void solve(int n, string res, vector<string> &result, int open, int close)
    {
        if (res.size() == 2 * n)
        {
            result.push_back(res);
            return;
        }
        if (open < n)
        {
            solve(n, res + '(', result, open + 1, close);
        }
        if (close < open)
            solve(n, res + ')', result, open, close + 1);
    }

    vector<string> generateParenthesis(int n)
    {

        vector<string> result;

        solve(n, "", result, 0, 0);
        return result;
    }
};