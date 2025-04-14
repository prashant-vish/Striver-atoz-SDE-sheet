#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity:O(n^4*log(n))
// Space Complexity:O(2n+n+N)=> O(n)

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        int n = nums.size();

        set<vector<int>> st; // O(2*n)

        for (int i = 0; i < n; i++)
        { // O(n)
            for (int j = i + 1; j < n; j++)
            { // O(n)
                for (int k = j + 1; k < n; k++)
                { // O(n)
                    for (int l = k + 1; l < n; l++)
                    { // O(n)
                        long long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if (sum == target)
                        {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]}; // O(n)
                            sort(temp.begin(), temp.end());
                            st.insert(temp); // O(logn)
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end()); // O(N)
        return ans;
    }
};

// Optimal Code

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size(); // size of the array
        vector<vector<int>> ans;

        // sort the given array:
        sort(nums.begin(), nums.end());

        // calculating the quadruplets:
        for (int i = 0; i < n; i++)
        {
            // avoid the duplicates while moving i:
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                // avoid the duplicates while moving j:
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // 2 pointers:
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        // skip the duplicates:
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }

        return ans;
    }
};