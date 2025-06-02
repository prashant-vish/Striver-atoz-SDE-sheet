#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n^2)
// Space complexity : O(n)

class Solution
{
public:
    void solve(vector<int> &nums, int idx, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (idx == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp, ans);
        temp.pop_back();

        solve(nums, idx + 1, temp, ans);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, 0, temp, ans);
        return ans;
    }
};

// optimal Solution : O(n*n);
// space complexity :O(1)
class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int n=1<<(nums.size());

        for(int i=0;i<n;i++){
            int num=i;
            vector<int> temp;
            for(int i=0;i<nums.size();i++){

                if(num&(1<<i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;

        
        return ans;
    }
};