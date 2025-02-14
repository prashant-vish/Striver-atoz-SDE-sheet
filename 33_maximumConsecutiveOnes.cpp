#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {

        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            while (i < n && nums[i])
            {
                cnt++;
                i++;
            }
            ans = max(cnt, ans);
        }
        return ans;
    }
};