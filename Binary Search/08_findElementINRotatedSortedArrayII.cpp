#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        bool search(vector<int>& arr, int target) {
            
            int l=0;
            int h=arr.size()-1;
            int mid;
    
            while(l<=h){
                int mid=(l+h)/2;
                if(arr[mid]==target){
                    return true;
                }
                if(arr[l]==arr[mid]&& arr[h]==arr[mid]){
                    l=l+1;
                    h=h-1;
                    continue;
                }
                if(arr[l]<=arr[mid]){
                    if(target>=arr[l]&& target<=arr[mid]){
                       h=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                else{
                    if(target>=arr[mid]&& target<=arr[h]){
                        l=mid+1;
                    }
                    else{
                        h=mid-1;
                    }
                }
            }
            return false;
        }
    };