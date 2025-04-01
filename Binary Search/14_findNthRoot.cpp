#include <bits/stdc++.h>
using namespace std;

// Brute Force Code - Linear Search
// Time complexity O(nm) where n<30---> O(m)
// Space complexity O(1)

class Solution
{
public:
    int ntimes(int i, int n)
    {

        long long ans = 1;
        for (int j = 1; j <= n; j++)
        {
            ans = ans * i;
        }
        return ans;
    }
    int nthRoot(int n, int m)
    {

        for (int i = 1; i <= ntimes(i, n); i++)
        {
            if (ntimes(i, n) == m)
            {
                return i;
            }
            if (ntimes(i, n) > m)
            {
                return -1;
            }
        }
        return -1;
    }
};
// OPtimal Code - Binary Search
// Time complexity O(nlogm) where n<30 O(logm)
// Space complexity O(1)

class Solution
{
public:
    int ntimes(int i, int n)
    {

        long long ans = 1;
        for (int j = 1; j <= n; j++)
        {
            ans = ans * i;
        }
        return ans;
    }
    int nthRoot(int n, int m)
    {
        int l = 1;
        int h = m;
        int mid;

        while (l <= h)
        {
            mid = (l + h) / 2;

            if (ntimes(mid, n) == m)
            {
                return mid;
            }
            else if (ntimes(mid, n) > m)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};