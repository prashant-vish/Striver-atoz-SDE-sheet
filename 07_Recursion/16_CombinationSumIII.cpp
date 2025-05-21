#include <bits/stdc++.h>
using namespace std;

// Time Complexity : K*2^9

// Space Compleixity : O(1)

class Solution
{
public:
    void solve(vector<int> &arr, int idx, int k, int n, int target, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (ds.size() == k && target == n)
        {
            ans.push_back(ds);
            return;
        }
        if (ds.size() > k || target > n || idx >= arr.size())
        {
            return;
        }
        target += arr[idx];
        ds.push_back(arr[idx]);
        solve(arr, idx + 1, k, n, target, ds, ans);
        target -= arr[idx];
        ds.pop_back();

        solve(arr, idx + 1, k, n, target, ds, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        vector<int> ds;
        vector<vector<int>> ans;
        int target = 0;

        solve(arr, 0, k, n, target, ds, ans);
        return ans;
    }
};