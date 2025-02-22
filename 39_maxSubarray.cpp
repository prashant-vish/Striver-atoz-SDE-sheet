#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
//  Time Complexity: O(n^2)
//  Space Complexity: O(1)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int maxsum = INT_MIN;
        int maxLen = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum = sum + nums[j];
                if (sum > maxsum)
                {
                    maxsum = sum;
                    maxLen = j - i + 1;
                }
            }
        }
        return maxsum;
    }
};

// Optimal Solution: Using Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int maxsum = INT_MIN;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {

            sum = sum + nums[i];
            if (sum > maxsum)
            {
                maxsum = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxsum;
    }
};