#include <bits/stdc++.h>
using namespace std;
// brute Force
// time comlexity =O(n)
// space complexity=O(1)
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {

        int total = arr[0] - 1;
        if (total >= k)
        {
            return k;
        }
        int prevTotal;
        for (int i = 1; i < arr.size(); i++)
        {
            prevTotal = total;
            total = arr[i] - (i + 1);
            if (total >= k)
            {
                return arr[i - 1] + (k - prevTotal);
            }
        }
        return arr[arr.size() - 1] + (k - total);
    }
};