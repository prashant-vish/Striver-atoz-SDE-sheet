#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gcda(long long A, long long B)
    {

        while (A > 0 && B > 0)
        {
            if (A > B)
                A = A % B;
            else
            {
                B = B % A;
            }
        }
        if (A == 0)
            return B;
        return A;
    }
    vector<long long> lcmAndGcd(long long A, long long B)
    {

        vector<long long> ans(2, 0);
        long long gcd = gcda(A, B);

        ans[1] = gcd;
        ans[0] = (A * B) / gcd;

        return ans;
    }
};