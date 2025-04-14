#include <bits/stdc++.h>
using namespace std;

// Optimal Solution:
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    // Function to find pair with maximum sum
    // The will always be sum of two consecutive elements
    int pairWithMaxSum(vector<int> &arr)
    {

        int n = arr.size();
        int maxSum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int sum = arr[i] + arr[i + 1];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};