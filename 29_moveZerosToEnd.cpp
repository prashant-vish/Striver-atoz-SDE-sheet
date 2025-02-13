#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int i = 0;
        for (; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                break;
            }
        }
        int j = i + 1;
        while (j < nums.size() && i < nums.size())
        {
            if (nums[j] != 0)
            {
                swap(nums[i], nums[j]);
            }
            while (i < nums.size() && nums[i])
            {
                i++;
            }
            while (j < nums.size() && !nums[j])
            {
                j++;
            }
        }
    }
};