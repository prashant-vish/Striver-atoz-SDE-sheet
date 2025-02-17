#include <bits/stdc++.h>
using namespace std;

// Better Approach using Counting Sort
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int countZero = 0;
        int countOne = 0;
        int countTwo = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                countZero++;
            else if (nums[i] == 1)
                countOne++;
            else
                countTwo++;
        }
        int i = 0;
        while (countZero--)
        {
            nums[i++] = 0;
        }
        while (countOne--)
        {
            nums[i++] = 1;
        }
        while (countTwo--)
        {
            nums[i++] = 2;
        }
    }
};
// Optimized Approach using Dutch National Flag Algorithm
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};