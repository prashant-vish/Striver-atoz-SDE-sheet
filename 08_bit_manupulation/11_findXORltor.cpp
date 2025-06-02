// brute force solution
// time complexity - O(n)
// space complexity - O(1)

class Solution
{
public:
    int findXOR(int l, int r)
    {
        // complete the function here
        int ans = l;
        for (int i = l + 1; i <= r; i++)
        {
            ans = ans ^ (i);
        }

        return ans;
    }
};

// optimal solution - time complexity O(1)
// space complexity - O(1);

class Solution
{
public:
    int solve(int n)
    {

        if (n % 4 == 1)
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else if (n % 4 == 3)
            return 0;
        else
            return n;
    }
    int findXOR(int l, int r)
    {
        // complete the function here

        return solve(l - 1) ^ solve(r);
    }
};