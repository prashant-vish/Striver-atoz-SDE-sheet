#include <bits/stdc++.h>
using namespace std;

// time complexity O(k*2^n+nlogn)
// space complexity O(n) stack space 
class Solution {
public:
    void solve(vector<int> &candidates,int target,int sum , int idx,vector<int> &ds, vector<vector<int>> &ans){

        if(target<sum||idx==candidates.size()){
            if(target==sum){
                ans.push_back(ds);
            }
            return ;
        }
        if(target==sum){
            ans.push_back(ds);
            return ;
        }

        sum+=candidates[idx];
        ds.push_back(candidates[idx]);
        solve(candidates,target, sum,idx+1,ds,ans);
        ds.pop_back();
        sum-=candidates[idx];
        while(idx+1<candidates.size() && candidates[idx]==candidates[idx+1]){
            idx++;
        }

        solve(candidates, target,sum, idx+1, ds,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int> > ans;
        solve(candidates,target,0 ,0 ,ds, ans);
        return ans;
    }
};