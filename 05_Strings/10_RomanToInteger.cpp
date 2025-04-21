#include <bits/stdc++.h>
using namespace std;
// brute force/optimal
// time complexity -O(n)
// space complexity -O(1)

class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.size();
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int previous = INT_MIN;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = mpp[s[i]];
            if (previous > curr)
            {
                ans -= mpp[s[i]];
            }
            else
            {
                ans += mpp[s[i]];
            }
            previous = mpp[s[i]];
        }
        return ans;
    }
};