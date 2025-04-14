#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n)+O(n) = O(n)
// Space Complexity: O(n)

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> positive;
        vector<int> negative;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                positive.push_back(nums[i]);
            }
            else
            {
                negative.push_back(nums[i]);
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            nums[2 * i] = positive[i];
            nums[2 * i + 1] = negative[i];
        }
        return nums;
    }
};

// Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> ans(n, 0);
        int even = 0, odd = 1;
        for (auto it : nums)
        {
            if (it > 0)
            {
                ans[even] = it;
                even = even + 2;
            }
            else
            {
                ans[odd] = it;
                odd = odd + 2;
            }
        }
        return ans;
    }
};