#include <bits/stdc++.h>
using namespace std;
//Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Just count each one and check if it is greater than n/2
// Method 1: Using unordered_map
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mpp[nums[i]]++;
        for (auto it : mpp)
        {
            if (it.second > n / 2)
                return it.first;
        }
        return -1;
    }
};


// Method 2: Using Moore's Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            
            int element;
            int count=0;
    
            for(int i=0;i<nums.size();i++){
                
                if(count==0){
                    element=nums[i];
                }
                if(nums[i]==element){
                    count++;
                }
                else{
                    count--;
                }
            }
            return element;
        }
    };