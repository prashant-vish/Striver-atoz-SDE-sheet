#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &arr, int m, int k, int day)
    {
        int n = arr.size(); // size of the array
        int cnt = 0;
        int noOfB = 0;
        // count the number of bouquets:
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= day)
            {
                cnt++;
            }
            else
            {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {

        long long n = bloomDay.size();
        long long val = long(k) * long(m);
        if (n < val)
            return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int ans = INT_MAX;
        int mid;
        int l = mini;
        int h = maxi;
        while (l <= h)
        {
            mid = (l + h) / 2;
            bool check = possible(bloomDay, m, k, mid);
            if (check)
            {
                ans = min(ans, mid);
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};