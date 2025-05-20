#include <bits/stdc++.h>
using namespace std;

// time complexity O(2^n)
// space complexity O(n)

class Solution
{
public:
    bool solve(vector<int> &arr, int sum, int index, int total)
    {

        if (index >= arr.size())
        {
            if (total == sum)
            {
                return true;
            }
            return false;
        }
        total += arr[index];
        if (solve(arr, sum, index + 1, total))
            return true;
        total -= arr[index];

        if (solve(arr, sum, index + 1, total))
            return true;

        return false;
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        return solve(arr, sum, 0, 0);
    }
};