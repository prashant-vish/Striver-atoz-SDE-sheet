#include <bits/stdc++.h>
using namespace std;

// Brute Force
// time complexity : O((high-low)*n) where high is sum of all the elements weights and low is the highest element of the weights and n is the lenght of the array
// Space complexity : O(1)

class Solution
{
public:
    bool checkIfPossible(vector<int> &weights, int days, int capacity)
    {
        int totalDays = 0;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (sum + weights[i] <= capacity)
            {
                sum += weights[i];
            }
            else
            {
                totalDays++;
                sum = weights[i];
            }
        }
        if (sum != 0)
            totalDays++;
        return totalDays <= days ? true : false;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int high = 0;
        int low = INT_MIN;
        for (int i = 0; i < weights.size(); i++)
        {
            high += weights[i];
            low = max(weights[i], low);
        }
        for (int i = low; i <= high; i++)
        {
            if (checkIfPossible(weights, days, i))
                return i;
        }
        return -1;
    }
};

// Optimal Solution
// Time Complexity :  O(n*log(high-low))
// Space Complexity:    O(1)

class Solution
{
public:
    bool checkIfPossible(vector<int> &weights, int days, int capacity)
    {
        int totalDays = 0;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (sum + weights[i] <= capacity)
            {
                sum += weights[i];
            }
            else
            {
                totalDays++;
                sum = weights[i];
            }
        }
        if (sum != 0)
            totalDays++;
        return totalDays <= days ? true : false;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int high = 0;
        int low = INT_MIN;
        for (int i = 0; i < weights.size(); i++)
        {
            high += weights[i];
            low = max(weights[i], low);
        }
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (checkIfPossible(weights, days, mid))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};