#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity - O((sum-max)*N)
// space Complexity -O(1)
class Solution
{
public:
    int allocatePages(int pages, vector<int> &arr, int n)
    {
        int student = 1;
        int studentPage = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] + studentPage <= pages)
            {
                studentPage += arr[i];
            }
            else
            {
                studentPage = arr[i];
                student++;
            }
        }
        return student;
    }

    int findPages(vector<int> &arr, int n, int m)
    {
        if (m > n)
            return -1;

        int low = INT_MIN, high = 0;
        for (int i = 0; i < n; i++)
        {
            low = max(arr[i], low);
            high += arr[i];
        }
        int ans = INT_MAX;
        for (int page = low; page <= high; page++)
        {
            int student = allocatePages(page, arr, n);
            if (student == m)
                return page;
        }
        return low;
    }
    int splitArray(vector<int> &nums, int k)
    {
        return findPages(nums, nums.size(), k);
    }
};

// Brute Force
// Time Complexity - O(N* log(sum-max))
// space Complexity -O(1)
class Solution
{
public:
    int allocatePages(int pages, vector<int> &arr, int n)
    {
        int student = 1;
        int studentPage = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] + studentPage <= pages)
            {
                studentPage += arr[i];
            }
            else
            {
                studentPage = arr[i];
                student++;
            }
        }
        return student;
    }

    int findPages(vector<int> &arr, int n, int m)
    {
        if (m > n)
            return -1;

        int low = INT_MIN, high = 0;
        for (int i = 0; i < n; i++)
        {
            low = max(arr[i], low);
            high += arr[i];
        }
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int student = allocatePages(mid, arr, n);
            if (student <= m)
                high = mid - 1;
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
    int splitArray(vector<int> &nums, int k)
    {
        return findPages(nums, nums.size(), k);
    }
};
