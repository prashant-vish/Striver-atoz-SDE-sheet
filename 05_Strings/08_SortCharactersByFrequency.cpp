#include <bits/stdc++.h>
using namespace std;

// brute force / optimal
// time complexity - O(nlog(n));
// space complexity -O(n)

class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mpp;
        for (int i = 0; i < s.size(); i++)
        {
            mpp[s[i]]++;
        }
        vector<pair<char, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
             { return a.second < b.second; });
        string ans;
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            auto it = vec[i];
            int n = it.second;
            while (n--)
            {
                ans += it.first;
            }
        }
        return ans;
    }
};