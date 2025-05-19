#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n^2)
// space complexity - O(n)

class Solution {
  public:
  
    void solve(int num,string str,vector<string> &result){
            
        if(str.length()==num){
            result.push_back(str);
            return;
        }
        
        
        solve(num, str+"0", result);
        
        if(str.empty()||str.back()!='1'){
            solve(num,str+"1",result);
        }
    }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> result;
        solve(num,"",result);
        return result;
    }
};