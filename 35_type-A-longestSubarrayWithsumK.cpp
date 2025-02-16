#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {

        unordered_map<int, int> prefixSumMap;
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];

            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            int rem = sum - k;

            if (prefixSumMap.find(rem) != prefixSumMap.end())
            {
                int len = i - prefixSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if (prefixSumMap.find(sum) == prefixSumMap.end())
                prefixSumMap[sum] = i;
        }
        return maxLen;
    }
};