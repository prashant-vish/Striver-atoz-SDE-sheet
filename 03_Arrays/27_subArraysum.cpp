#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {

        int n = arr.size();
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> preSum;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            if (sum == k)
            {
                ans++;
            }
            int rem = sum - k;
            if (preSum.find(rem) != preSum.end())
            {
                ans = ans + preSum[rem];
            }
            preSum[sum] = preSum[sum] + 1;
        }
        return ans;
    }
};