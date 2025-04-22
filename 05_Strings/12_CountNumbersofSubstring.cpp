#include <bits/stdc++.h>
using namespace std;
// brute force
// time complexity -O(n)
// space comlexity -O(n)

class Solution
{
public:
    int countHomogenous(string s)
    {

        long long ans = 0;
        char prev = s[0];
        string str = "";
        str += s[0];

        for (long long i = 1; i < s.size(); i++)
        {
            char curr = s[i];

            if (curr == prev)
            {
                str += curr;
            }
            else
            {
                long long m = str.size();
                ans = ans + ((long long)(m * (m + 1)) / 2);
                prev = curr;
                str = "";
                str += curr;
            }
        }
        long long m = str.size();
        cout << m;
        ans = ans + ((long long)(m * (m + 1)) / 2);
        return (int)(ans % 1000000007);
    }
};

// optimal solution
// time complexity - O(n)
// space complexity - O(1)

class Solution
{
public:
    int countHomogenous(string s)
    {

        int left = 0;
        long long ans = 0;

        for (int right = 0; right < s.size(); right++)
        {

            if (s[left] == s[right])
            {
                ans += right - left + 1;
            }
            else
            {
                ans += 1;
                left = right;
            }
        }
        return (int)(ans % (1000000007));
    }
};