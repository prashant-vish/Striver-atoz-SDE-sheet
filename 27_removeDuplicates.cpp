#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int j = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[j] != nums[i])
            {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }
};