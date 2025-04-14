#include <bits/stdc++.h>
using namespace std;
// time complexity=O(n)
// space complexity=o(1)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        if (arr[0] != arr[1])
            return arr[0];
        if (arr[n - 1] != arr[n - 2])
            return arr[n - 1];

        int l = 1, h = n - 2, mid;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
                return arr[mid];
            else if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
                l = mid + 1;
            else
                h = mid - 1;
        }
        return arr[mid];
    }
};