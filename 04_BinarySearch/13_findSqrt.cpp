#include <bits/stdc++.h>
using namespace std;

// Brute force -Linear Search 
// Time Complexity sqrt(n)
// Space Complexity O(1)
class Solution {
    public:
      int floorSqrt(int n) {
          int i;
          for( i=1;i*i<=n;i++){
              if(i*i==n){
                  return i;
              }
          }
          return i-1;
      }
  };


// Optimal Code -Binary Search
// time complexity log(n)
// space Complexity O(1)
class Solution {
    public:
      int floorSqrt(int n) {
          int l=0;
          int h=n;
          
          while(l<=h){
              int mid=(l+h)/2;
              if(mid*mid==n){
                  return mid;
              }
              else if(mid*mid>n){
                  h=mid-1;
              }
              else{
                  l=mid+1;
              }
          }
          return h;
      }
  };