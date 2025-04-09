#include <bits/stdc++.h>
using namespace std;

// brute force
// time complexity - O(maxi*n);
// space complexity -O(1);
class Solution
{
public:
    bool checkDivisible(vector<int> &nums, int threshold, int divisor)
    {
        long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] / divisor;
            if (nums[i] % divisor != 0)
            {
                sum++;
            }
        }
        return sum <= threshold ? true : false;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {

        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(nums[i], maxi);
        }
        for (int i = 1; i <= maxi; i++)
        {
            if (checkDivisible(nums, threshold, i))
            {
                return i;
            }
        }
        return -1;
    }
};

// Optimal Solution
// time Complexity O(log(maxi)*n) where maxi is the largest element in the array
// space complexity O(1)

class Solution
{
public:
    bool checkDivisible(vector<int> &nums, int threshold, int divisor)
    {
        long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] / divisor;
            if (nums[i] % divisor != 0)
            {
                sum++;
            }
        }
        return sum <= threshold ? true : false;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            high = max(nums[i], high);
        }
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (checkDivisible(nums, threshold, mid))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};