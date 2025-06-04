#include <bits/stdc++.h>
using namespace std;
// brute force -

// time complexity - O(n(log(n)))
// Space comeplexity - O(m) where m < =n/2+1

class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {

        unordered_map<long long, int> mpp;
        vector<long long int> ans;

        for (long long i = 0; i < N; i++)
        {
            mpp[Arr[i]]++;
        }

        for (auto it : mpp)
        {
            if (it.second % 2 != 0)
            {
                ans.push_back(it.first);
            }
        }
        if (ans[0] > ans[1])
        {
            return {ans[0], ans[1]};
        }
        return {ans[1], ans[0]};
    }
};


// Optimal solution 
// Time complexity - O(n)
// Space complexity - O(1)

class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        // code here
        int num = 0;
        for (long long i = 0; i < N; i++)
        {
            num = num ^ Arr[i];
        }

        int rightmost = num & (num - 1) ^ num;

        int b1 = 0;
        int b2 = 0;

        for (int i = 0; i < N; i++)
        {
            if (Arr[i] & rightmost)
            {
                b1 = b1 ^ Arr[i];
            }
            else
                b2 = b2 ^ Arr[i];
        }

        if (b1 > b2)
        {
            return {b1, b2};
        }
        return {b2, b1};
    }
};