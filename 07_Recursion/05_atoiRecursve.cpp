#include <bits/stdc++.h>
using namespace std;

// time complexity = O(n)
// space complexity =O(n) stack space

class Solution
{
public:
    bool checkDigit(char ch)
    {

        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
        {
            return true;
        }
        return false;
    }

    int solve(string s, int idx, int sign, long long res)
    {

        if (idx == s.size() || !checkDigit(s[idx]))
            return res * sign;

        res = res * 10 + (s[idx] - '0');

        if (sign * res > INT_MAX)
            return INT_MAX;
        if (sign * res < INT_MIN)
            return INT_MIN;

        return solve(s, idx + 1, sign, res);
    }
    int myAtoi(string s)
    {
        size_t start = s.find_first_not_of(" ");

        if (start == string::npos)
            return 0;
        s = s.substr(start);

        if (s.empty())
            return 0;
        int sign = 1, index = 0;

        if (s[0] == '-')
            sign = -1, index++;
        else if (s[0] == '+')
            index++;
        return solve(s, index, sign, 0);
    }
};