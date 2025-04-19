#include <bits/stdc++.h>
using namespace std;
// time complexity O(n)
//  space complexity O(1)
class Solution
{
public:
    string largestOddNumber(string num)
    {

        int n = num.size();

        while (n--)
        {
            if ((num[n] - 48) % 2 == 1)
            {
                return num.substr(0, n + 1);
            }
        }
        return "";
    }
};