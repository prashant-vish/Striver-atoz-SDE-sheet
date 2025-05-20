#include <bits/stdc++.h>
using namespace std;

// time complexity - O(2^n)
// space complexity O(n) stack space;

class Solution
{
public:
    int solve(vector<int> &arr, int target, int index, int sum)
    {

        if (index >= arr.size())
        {

            if (target == sum)
            {
                return 1;
            }
            return 0;
        }
        sum += arr[index];
        int left = solve(arr, target, index + 1, sum);
        sum -= arr[index];
        int right = solve(arr, target, index + 1, sum);

        return left + right;
    }
    int perfectSum(vector<int> &arr, int target)
    {
        // code here

        return solve(arr, target, 0, 0);
    }
};