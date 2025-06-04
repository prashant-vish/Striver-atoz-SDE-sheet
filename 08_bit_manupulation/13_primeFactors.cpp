#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isprime(int n)
    {
        if (n == 1)
        {
            return false;
        }
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return true;
    }
    vector<int> AllPrimeFactors(int N)
    {
        // Code here

        vector<int> ans;

        for (int i = 2; i * i <= N; i++)
        {

            if (N % i == 0)
            {
                if (isprime(i))
                {
                    ans.push_back(i);
                }
                if (N / i != i)
                {
                    if (isprime(N / i))
                        ans.push_back(N / i);
                }
            }
        }

        if (isprime(N))
        {
            ans.push_back(N);
        }
        return ans;
    }
};



// Optimal Solution 


class Solution {
  public:
    
    vector<int> AllPrimeFactors(int N) {
        // Code here
        vector<int> ans;
        
        for(int i=2;i*i<=N;i++){
            if(N%i==0){
                ans.push_back(i);
                while(N%i==0){
                    N=N/i;
                }
            }
        }
        if(N!=1){
            ans.push_back(N);
        }
        return ans;
    }
};