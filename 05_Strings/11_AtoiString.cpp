#include <bits/stdc++.h>
using namespace std;

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
    int myAtoi(string s)
    {

        int i = 0, sign = 1;
        long res = 0;

        while (i < s.size() && s[i] == ' ')
            i++;

        if (i == s.size())
            return 0;

        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;

        while (i < s.size() && checkDigit(s[i]))
        {

            res = res * 10 + (s[i] - '0');

            if (sign * res > INT_MAX)
                return INT_MAX;
            if (sign * res < INT_MIN)
                return INT_MIN;

            i++;
        }
        return (int)(sign * res);
    }
};