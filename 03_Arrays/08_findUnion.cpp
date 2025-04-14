#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // a,b : the arrays
      // Function to return a list containing the union of the two arrays.
      vector<int> findUnion(vector<int> &a, vector<int> &b) {
          // Your code here
          vector<int> ans;
          set<int> temp;
          for(int i=0;i<a.size();i++){
              temp.insert(a[i]);
          }
          for(int j=0;j<b.size();j++){
              temp.insert(b[j]);
          }
          for(int it:temp){
              ans.push_back(it);
          }
          return ans;
      }
  };