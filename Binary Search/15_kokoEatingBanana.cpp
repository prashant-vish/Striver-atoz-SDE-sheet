#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// time Complexity- O(n^2)
// Space Complexity O(1)


// Optimal Solution 
// time Complexity O(nlogn)
// space Complexity O(1)

class Solution {
    public:
    
        long long timetoEat(vector<int> &piles, int mid){
            long long sum=0;
            for(int i=0;i<piles.size();i++){
                long long  value=piles[i]/mid;
                if(piles[i]%mid==0){
                    sum+=value;
                    continue;
                }
                sum+= value+1;
            }
            return sum;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            
            int maxi=INT_MIN;
            for(int i=0;i<piles.size();i++){
                maxi=max(maxi,piles[i]);
            }
            int low=1;int high=maxi;
            int mid;
            int ans=INT_MAX;
            while(low<=high){
                mid=(low+high)/2;
                long long minTime=timetoEat(piles, mid);
                if(minTime<=h){
                    ans=min(ans,mid);
                    high=mid-1;
                }
                else if(minTime>h){
                    low=mid+1;
                }
    
            }
            return ans;
        }
    };