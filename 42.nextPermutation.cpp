#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n!)*O(n) = O(n*n!)
// Space Complexity: 0(1)

// just write next_permutation(nums.begin(), nums.end()) in the main function
// and it will give the next permutation of the given vector

// Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size();
        int idx = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            return reverse(nums.begin(), nums.end());
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[idx])
            {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        return reverse(nums.begin() + idx + 1, nums.end());
    }
};