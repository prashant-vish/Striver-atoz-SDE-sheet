#include <bits/stdc++.h>
using namespace std;

// time complexity O(4^n )
// space complexity O(n*4^n)


class Solution {
public:
    void solve(string &digits,vector<string>&arr, int idx, string& ds ,vector<string>&ans){
        
        if(idx>=digits.size()){
            if(ds.size()!=0 && ds.size()==digits.size()){
                ans.push_back(ds);
            }
            return ;
        }
        for(int i=0;i<arr[digits[idx]-'0'].size();i++){
            ds.push_back(arr[digits[idx]-'0'][i]);
            solve(digits,arr,idx+1,ds, ans);
            ds.pop_back();

        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        string ds="";
        vector<string> arr{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,arr,0,ds,ans);
        return ans;
    }
};