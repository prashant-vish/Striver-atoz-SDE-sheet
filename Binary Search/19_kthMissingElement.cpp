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

// Another One
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= k)
                k++;
            else
                break;
        }

        return k;
    }
};

// Optimal Solution
// time Complexity - O(log(n))
// space complexity -O(1)

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {

        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low + k;
    }
};