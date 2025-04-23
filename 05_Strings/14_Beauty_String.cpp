#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> mpp;
            for (int j = i; j < n; j++)
            {
                mpp[s[j]]++;
                int max_freq = 0, min_freq = INT_MAX;
                for (auto it : mpp)
                {
                    max_freq = max(max_freq, it.second);
                    min_freq = min(min_freq, it.second);
                }
                ans += max_freq - min_freq;
            }
        }
        return ans;
    }
};