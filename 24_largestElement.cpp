// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largest(vector<int> &arr)
    {

        int n = arr.size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= maxi)
            {
                maxi = arr[i];
            }
        }

        return maxi;
    }
};