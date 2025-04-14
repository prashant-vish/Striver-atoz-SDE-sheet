#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {

        int maxdiff = 0;
        int n = arr.size();

        for (int i = 0; i < n - 1; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                int diff = arr[j] - arr[i];
                maxdiff = max(diff, maxdiff);
            }
        }
        return maxdiff;
    }
};

// Optimal Solution
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {

        int maxdiff = 0;
        int n = arr.size();
        int mini = arr[0];
        for (int i = 1; i < n; i++)
        {
            int diff = arr[i] - mini;
            maxdiff = max(diff, maxdiff);
            if (arr[i] < mini)
                mini = arr[i];
        }
        return maxdiff;
    }
};