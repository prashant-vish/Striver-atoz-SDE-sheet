#include <bits/stdc++.h>
using namespace std;

// Brute force
// Time comlexity -O((sum-high)*n)
// Space complexity -O(1)
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
    for (int page = low; page <= high; page++)
    {
        int student = allocatePages(page, arr, n);
        if (student == m)
        {
            return page;
        }
    }
    return low;
}

// Optimal Solution
// time complexity: O(n*log(sumation))
// space complexity :O(1)

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

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int student = allocatePages(mid, arr, n);
        if (student > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}