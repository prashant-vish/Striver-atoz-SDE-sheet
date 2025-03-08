#include <bits/stdc++.h>
using namespace std;

// Brute force approach:
// Time complexity: O(n^2)
// Space complexity: O(1)

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {

        int maxi = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < arr.size(); i++)
            {
                sum += arr[j];
                if (sum == 0)
                {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};

// Optimized approach:
// Time complexity: O(nlogn)
// Space complexity: O(n)

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        int maxi = 0;

        unordered_map<int, int> mpp;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];

            if (sum == 0)
            {
                maxi = i + 1;
            }
            else
            {

                if (mpp.find(sum) != mpp.end())
                {
                    maxi = max(maxi, i - mpp[sum]);
                }
                else
                {
                    mpp[sum] = i;
                }
            }
        }
        return maxi;
    }
};