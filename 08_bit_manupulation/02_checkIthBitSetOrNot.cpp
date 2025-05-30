class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        // Your code here

        bool val = n & (1 << k) ? true : false;
        return val;
    }
};