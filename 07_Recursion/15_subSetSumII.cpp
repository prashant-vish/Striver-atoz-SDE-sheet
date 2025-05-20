#include <bits/stdc++.h>
using namespace std;


// time complexity (k*2^n+nlogn) k is avg size fo subset 
// space complexity (O(k)) where k is avg length of subset


class Solution {
public:
    void solve(vector<int> & nums, int idx, vector<int> &ds, vector<vector<int>> &ans){

        if(idx==nums.size()){
            ans.push_back(ds);
            return ;
        }
        ds.push_back(nums[idx]);
        solve(nums, idx+1, ds, ans);
        ds.pop_back();

        while(idx+1<nums.size()&& nums[idx]==nums[idx+1]) idx++;

        solve(nums,idx+1, ds, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> ds;
        solve(nums, 0, ds, ans);

        return ans;
    }
};