#include <bits/stdc++.h>
using namespace std;
// time complexity O(2^t) where t is target
// space complexity O(k*n) auxialary space.
class Solution
{
public:
    void solve(vector<int> &candidates, int target, int sum, int idx, vector<int> &ds, vector<vector<int>> &ans)
    {

        if (idx >= candidates.size())
        {
            if (target == sum)
            {
                ans.push_back(ds);
                return;
            }
            return;
        }
        if (target == sum)
        {
            ans.push_back(ds);
            return;
        }
        if (target < sum)
        {
            return;
        }
        sum += candidates[idx];
        ds.push_back(candidates[idx]);
        solve(candidates, target, sum, idx, ds, ans);
        ds.pop_back();
        sum -= candidates[idx];

        solve(candidates, target, sum, idx + 1, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates, target, 0, 0, ds, ans);
        return ans;
    }
};