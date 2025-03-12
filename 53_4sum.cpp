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

// Better Approach
// Time Complexity:O(n^4*log(n))
// Space Complexity:O(2n+n+N)=> O(n)