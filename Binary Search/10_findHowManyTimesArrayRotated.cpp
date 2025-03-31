#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findKRotation(vector<int> &arr) {
          
          int l=0;
          int h=arr.size()-1;
          int ans=INT_MAX;
          int index=0;
          while(l<=h){
              int mid=(l+h)/2;
               if(arr[l]<=arr[h]){
                   if(arr[l]<ans){
                       ans=arr[l];
                       index=l;
                   }
                      break;
                  }
              if(arr[mid]>=arr[l]){
                   if(arr[l]<ans){
                       ans=arr[l];
                       index=l;
                   }
                  
                  l=mid+1;
              }
              else{
                   if(arr[mid]<ans){
                       ans=arr[mid];
                       index=mid;
                   }
                 
                  h=mid-1;
              }
          }
      return index;
  
      }
  };