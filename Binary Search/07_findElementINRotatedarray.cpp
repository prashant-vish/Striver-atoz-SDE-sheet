#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binarySearch(int l, int h, vector<int> arr, int target)
    {

        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] == target)
            {
                return mid;
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
        return -1;
    }
    int search(vector<int> &arr, int target)
    {

        int l = 0;
        int h = arr.size() - 1;
        int mid;

        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            if (arr[l] <= arr[mid])
            {
                if (target >= arr[l] && target <= arr[mid])
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (target >= arr[mid] && target <= arr[h])
                {
                    l = mid - 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};