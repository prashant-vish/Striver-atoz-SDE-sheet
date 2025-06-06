#include <bits/stdc++.h>
using namespace std;


// time complexity=n(sqrt(n)(logn))
// space complexity= O(1)

class Solution
{
public:
    void sieve()
    {
        ;
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