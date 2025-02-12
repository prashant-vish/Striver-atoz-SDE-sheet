class Solution
{
public:
    int reverse(int x)
    {

        long ans = 0;
        while (x)
        {

            int r = x % 10;
            ans = ans * 10 + r;
            if (ans < -2147483648 || ans > 2147483647)
                return 0;
            x = x / 10;
        }
        return ans;
    }
};