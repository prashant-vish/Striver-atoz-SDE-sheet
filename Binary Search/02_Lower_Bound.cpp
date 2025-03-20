#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(nlogn)
// Space Complexity - O(1)

class Solution
{
public:
    int findFloor(vector<int> &arr, int x)
    {
        // Your code here
        int l = 0;
        int ans = -1;
        int h = arr.size() - 1;
        int mid;
        while (l <= h)
        {
            mid = (l + h) / 2;

            if (arr[mid] > x)
            {
                h = mid - 1;
            }
            else
            {
                ans = max(ans, mid);
                l = mid + 1;
            }
        }
        return ans;
    }
};