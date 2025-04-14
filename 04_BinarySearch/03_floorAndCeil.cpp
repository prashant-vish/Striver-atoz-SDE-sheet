#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
      vector<int> getFloorAndCeil(int x, vector<int> &arr) {
          
          int floor1=-1;;
          int ceil1=INT_MAX;
          
          for(int i=0;i<arr.size();i++){
              
              
              if(arr[i]<=x){
                  floor1=max(arr[i],floor1);
              }
              if(arr[i]>=x){
                  ceil1=min(arr[i],ceil1);
              }
          }
          return {floor1,ceil1==INT_MAX?-1: ceil1};
      }
  };