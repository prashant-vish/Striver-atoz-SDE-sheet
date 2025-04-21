#include <bits/stdc++.h>
using namespace std;
// Brute force / Optimal Approach
// time Complexity -O(n)
// Space complexity -O(1)

class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = INT_MIN;
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            ans = max(count, ans);
            if (s[i] == '(')
            {
                count++;
            }
            else if (s[i] == ')')
            {
                count--;
            }
        }
        return ans;
    }
};