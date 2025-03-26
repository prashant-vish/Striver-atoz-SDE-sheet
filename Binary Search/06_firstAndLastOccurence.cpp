#include <bits/stdc++.h>
using namespace std;

// Brute Force Time Complexity = O(n)
// Space complexity =O(1);
class Solution
{
public:
    vector<int> searchRange(vector<int> &arr, int target)
    {
        int l = 0;
        int h = arr.size() - 1;

        int mid;
        while (l <= h)
        {
            mid = (l + h) / 2;

            if (target == arr[mid])
            {

                int t = mid;

                while (mid > 0 && arr[mid] == arr[mid - 1])
                {
                    mid--;
                }
                while (t < arr.size() - 1 && arr[t] == arr[t + 1])
                {
                    t++;
                }
                return {mid, t};
            }
            else if (target > arr[mid])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return {-1, -1};
    }
};

// Optimal Approach
//  Time Complexity =O(logn);
//  Space Complexity=O(1);

class Solution
{
public:
    int lower_bound(vector<int> &arr, int target)
    {
        int l = 0;
        int h = arr.size() - 1;
        int mid;
        int ans = arr.size();
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (arr[mid] >= target)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    int upper_bound(vector<int> &arr, int target)
    {
        int l = 0;
        int h = arr.size() - 1;
        int mid;
        int ans = arr.size();
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (arr[mid] > target)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &arr, int target)
    {
        int lowerbound = lower_bound(arr, target);
        if (lowerbound == arr.size() || arr[lowerbound] != target)
            return {-1, -1};
        int upperbound = upper_bound(arr, target);
        return {lowerbound, upperbound - 1};
    }
};

// Optimal Solution using first and last occurence method
// Time complexity=O(logn)
// Space Complexity=o(1);

class Solution
{
public:
    int firstOccurence(vector<int> &arr, int target)
    {
        int l = 0;
        int h = arr.size() - 1;
        int size = arr.size();
        int ans = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] == target)
            {
                ans = mid;
                h = mid - 1;
            }
            else if (target < arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    int lastOccurence(vector<int> &arr, int target)
    {
        int l = 0;
        int h = arr.size() - 1;
        int size = arr.size();
        int ans = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] == target)
            {
                ans = mid;
                l = mid + 1;
            }
            else if (target < arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &arr, int target)
    {

        return {firstOccurence(arr, target), lastOccurence(arr, target)};
    }
};