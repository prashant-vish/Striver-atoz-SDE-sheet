// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long factorial(long long N)
    {
        if (N == 1)
        {
            return 1;
        }
        return N * factorial(N - 1);
    }
    vector<long long> solve(long long N)
    {

        vector<long long> ans;
        for (int i = 1; i <= N; i++)
        {
            long long fact = factorial(i);
            if (fact <= N)
            {
                ans.push_back(fact);
            }
            else
            {
                break;
            }
        }

        return ans;
    }
    vector<long long> factorialNumbers(long long n)
    {

        return solve(n);
    }
};