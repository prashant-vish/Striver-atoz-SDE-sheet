// User function template for C++

class Solution {
    public:
      long long sumOfSeries(long long n) {
          if(n==1){
              return 1;
          }
          long long ans=n*n*n;
          return ans+sumOfSeries(n-1);
         
      }
  };