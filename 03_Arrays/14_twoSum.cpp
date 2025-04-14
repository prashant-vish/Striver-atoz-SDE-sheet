#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int n = nums.size();
        map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            int first = nums[i];

            int moreNeeded = target - first;
            if (mpp.find(moreNeeded) != mpp.end())
            {
                return {i, mpp[moreNeeded]};
            }
            mpp[first] = i;
        }
        return {0, 9};
    }
};