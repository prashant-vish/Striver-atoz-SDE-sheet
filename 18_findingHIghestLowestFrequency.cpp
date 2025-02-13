#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bSearch(int target_idx, int k, vector<int> &nums, vector<long> &prefixSum)
    {

        int l = 0;
        int r = target_idx;
        int best_idx = target_idx;
        while (l <= r)
        {

            int mid = l + (r - l) / 2;

            long count = target_idx - mid + 1;
            long windowSum = count * nums[target_idx];
            long originalSum = prefixSum[target_idx] - prefixSum[mid] + nums[mid];

            int ops = windowSum - originalSum;

            if (ops > k)
            {
                l = mid + 1;
            }
            else
            {
                best_idx = mid;
                r = mid - 1;
            }
        }
        return target_idx - best_idx + 1;
    }
    int maxFrequency(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long> prefixSum(n);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefixSum[i] += prefixSum[i - 1] + nums[i];
        }
        int result = 0;
        for (int target_idx = 0; target_idx < n; target_idx++)
        {
            int freq = bSearch(target_idx, k, nums, prefixSum);
            result = max(result, freq);
        }

        return result;
    }
};