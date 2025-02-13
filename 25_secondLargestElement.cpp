// User function template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
    
      int getSecondLargest(vector<int> &arr) {
      
          int maxi=-1000;
          
          for(int i=0;i<arr.size();i++){
              if(arr[i]>maxi){
                  maxi=arr[i];
              }
          }
          
          int secondlargest=-1;
          for(int i=0;i<arr.size();i++){
              if(arr[i]<maxi&&arr[i]>secondlargest){
                  secondlargest=arr[i];
              }
          }
          return secondlargest;
      }
  };