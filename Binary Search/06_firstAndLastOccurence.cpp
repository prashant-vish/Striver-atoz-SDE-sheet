#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& arr, int target) {
            int l=0;
            int h=arr.size()-1;
    
            int mid;
            while(l<=h){
                mid=(l+h)/2;
    
                if(target==arr[mid]){
                    
                    int t=mid;
    
                    while(mid>0&&arr[mid]==arr[mid-1]){
                        mid--;
                    }
                    while(t<arr.size()-1&& arr[t]==arr[t+1]){
                        t++;
                    }
                    return {mid,t};
    
                }
                else if(target>arr[mid]){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            return {-1, -1};
        }
    };