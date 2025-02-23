#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n*log(n))
// Space Complexity: O(1)

// Sort the array.
// Traverse the array and for each element, check if it is greater than the previous element.
// If it is, then increment the count.  Else, update the maximum count found so far.
// Return the maximum count found so far.

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
    
            sort(nums.begin(),nums.end());
            int maxi=1;
            int n=nums.size();
            if(n==0) return 0;
            int cnt=1;
            for(int i=1;i<n;){
                if(nums[i]-nums[i-1]==1){
                    while(i<n && nums[i]-nums[i-1]==1){
                        cnt++;
                        i++;
                    }
                }
                else if(nums[i]-nums[i-1]==0){
                    i++;
                }
                else{
                    cnt=1;
                    i++;
                }
                maxi=max(cnt,maxi);
            }
            return maxi;
        }
    };