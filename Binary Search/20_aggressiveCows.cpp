#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
// time Complexity O(nlog(n))
// space Complexity O(1)

class Solution
{
public:
    bool canWePlace(int n, int c, vector<int> arr, int distance)
    {
        int cowCount = 1;
        int last = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - last >= distance)
            {
                last = arr[i];
                cowCount++;
            }
            if (cowCount >= c)
            {
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 1;
        int high = arr[n - 1] - arr[0];

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canWePlace(n, k, arr, mid) == true)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};