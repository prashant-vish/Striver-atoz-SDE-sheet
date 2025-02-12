#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string armstrongNumber(int n)
    {
        int r;
        int ans = 0;
        int num = n;
        while (n)
        {
            r = n % 10;
            ans = r * r * r + ans;
            n = n / 10;
        }
        if (num == ans)
            return "Yes";
        else
            return "No";
    }
};