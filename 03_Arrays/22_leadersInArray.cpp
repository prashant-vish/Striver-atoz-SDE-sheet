#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Traverse the array and for each element, check if it is greater than all the elements to its right.
// If it is, then push it into the result vector.
// Return the result vector.

// Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(1)
// Traverse the array from right to left and keep track of the maximum element found so far.
// If the current element is greater than the maximum element found so far, then push it into the result vector.
// Return the result vector.

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        // Code here

        vector<int> ans;
        int n = arr.size();
        ans.push_back(arr[n - 1]);
        int maxi = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= maxi)
            {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};