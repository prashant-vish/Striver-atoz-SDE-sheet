#include <bits/stdc++.h>
using namespace std;


// Brute force ------>>>> Linear Search 
// Time Complexity ===> O(n)
// Space Complexity ===> O(1)


// Bettter Approach / Optimal Approach
// Time Complexity ---->> O(logn)
// Space Complexity ---> O(1)

class Solution {
    public:
        int findMin(vector<int>& arr) {
            
            int l=0;
            int h=arr.size()-1;
    
            while(l<=h){
                int mid=(l+h)/2;
    
                if(mid>0 &&arr[mid]<arr[mid-1]){
                    return arr[mid];
                }
                else if(mid<arr.size()-1&&arr[mid]>arr[mid+1]){
                    return arr[mid+1];
                }
                else if(arr[mid]<arr[h]){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        return arr[0];
        }
    };


// Bettter Approach / Simplest Approach
// Time Complexity ---->> O(logn)
// Space Complexity ---> O(1)

class Solution {
    public:
        int findMin(vector<int>& arr) {
            
            int l=0;
            int h=arr.size()-1;
            int ans=INT_MAX;
            while(l<=h){
                int mid=(l+h)/2;
                if(arr[mid]>=arr[l]){
                    ans=min(arr[l],ans);
                    l=mid+1;
                }
                else{
                    ans=min(arr[mid],ans);
                    h=mid-1;
                }
            }
        return ans;
        }
    };

