#include <bits/stdc++.h>
using namespace std;

// brute force
// time complexity - O(n*sqrt(n))
// space complexity - O(1)
class Solution
{
public:
    bool isPrime(int n)
    {

        for (int i = 2; i * i <= n; i++)
        {

            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n)
    {

        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime(i))
            {
                cnt++;
            }
        }
        return cnt;
    }
};

// better solution

class Solution
{
public:
    int countPrimes(int n)
    {

        int prime[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            prime[i] = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                for (int j = 2 * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == 1)
            {
                cnt++;
            }
        }

        return cnt;
    }
};

// optimal Solution
// time complexity O(n*log(logn))+O(n)+ O(n)
// space complexity O(n)

class Solution
{
public:
    int countPrimes(int n)
    {

        int prime[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            prime[i] = 1;
        }

        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == 1)
            {
                cnt++;
            }
        }

        return cnt;
    }
};