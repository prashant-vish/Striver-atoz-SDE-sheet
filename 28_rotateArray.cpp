#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n=nums.size();
            k=k%n;
    
            vector<int> lastKelements;
    
            for(int i=n-k;i<n;i++){
                lastKelements.push_back(nums[i]);
            }
            int j=n-1;
            for(int i=n-k-1;i>=0;i--){
                nums[j]=nums[i];
                j--;
            }
            for(int i=0;i<k;i++){
                nums[i]=lastKelements[i];
            }
            return;
        }
    };