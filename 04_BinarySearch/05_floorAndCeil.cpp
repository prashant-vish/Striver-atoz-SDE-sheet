#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
{

    int floor = -1;
    int ciel = INT_MAX;

    int l = 0;
    int h = n - 1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;

        if (arr[mid] > x)
        {
            h = mid - 1;
        }
        else
        {
            floor = max(floor, arr[mid]);
            l = mid + 1;
        }
    }
    l = 0;
    h = n - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            ciel = min(ciel, arr[mid]);
            h = mid - 1;
        }
    }
    return {floor, ciel == INT_MAX ? -1 : ciel};
}