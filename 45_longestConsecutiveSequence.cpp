#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n*log(n))
// Space Complexity: O(1)

// Sort the array.
// Traverse the array and for each element, check if it is greater than the previous element.
// If it is, then increment the count.  Else, update the longestmum count found so far.
// Return the maximum count found so far.

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int longest = 1;
        int cnt = 0;
        int lastSmaller = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] - 1 == 1)
            {
                cnt++;
                lastSmaller = nums[i];
            }
            else if (lastSmaller != nums[i])
            {
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(cnt, longest);
        }
        return longest;
    }
};

// Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(n)

// Create a set and insert all the elements of the array into the set.
// Traverse the array and for each element, check if it is the starting element of a sequence.
// If it is, then increment the count and keep checking for the next elements in the sequence.
// Update the longestmum count found so far.
// Return the maximum count found so far.

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());

        int longest = 1;
        unordered_set<int> st;

        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x = x + 1;
                    cnt++;
                }
                longest = max(cnt, longest);
            }
        }
        return longest;
    }
};