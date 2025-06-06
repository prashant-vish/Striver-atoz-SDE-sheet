#include <bits/stdc++.h>
using namespace std;


// time complexity=n(sqrt(n)(logn))
// space complexity= O(1)

class Solution
{
public:
    void sieve(int n)
    {;
    }

    bool isPrime(int n)
    {

        if (n == 2 || n == 3)
        {
            return true;
        }

        for (int i = 2; i * i <= n; i++)
        {

            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findPrimeFactors(int n)
    {
        vector<int> ans;
        for (int i = 2; i <= n; i++)
        {
            if (isPrime(i))
            {
                while (n % i == 0)
                {
                    ans.push_back(i);
                    n = n / i;
                }
            }
        }
        return ans;
    }
};

// time complexity - O(n*log(logn))
// space complexity - O(n)

class Solution {
  public:
    void sieve() {
     
        ;
        
    }
    
  
    vector<int> findPrimeFactors(int n) {
        vector<int> ans;
        int arr[n+1];
        for(int i=0;i<=n;i++){
            arr[i]=1;
        }
        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<=n;j+=i){
                if(!arr[j]){
                    arr[j]=0;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(arr[i]){
                while(n%i==0){
                    ans.push_back(i);
                    n=n/i;
                }
            }
        }
        return ans;
    }
};