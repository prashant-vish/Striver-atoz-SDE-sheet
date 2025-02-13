#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &arr, int idx, int n)
    {
        if (idx >= n / 2)
        {
            return;
        }
        swap(arr[idx], arr[n - 1 - idx]);
        solve(arr, idx + 1, n);
    }
    void reverseArray(vector<int> &arr)
    {
        int n = arr.size();
        solve(arr, 0, n);
    }
};