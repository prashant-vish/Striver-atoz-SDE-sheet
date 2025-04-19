#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(nlog(s.size))
// Space complexity- (O(n))
class Solution
{
public:
    bool check(string s, string t)
    {
        int n = s.size();
        unordered_map<char, char> mpp;
        for (int i = 0; i < n; i++)
        {
            if (mpp.find(s[i]) != mpp.end())
            {
                if (mpp[s[i]] != t[i])
                {
                    return false;
                }
            }
            mpp[s[i]] = t[i];
        }
        return true;
        ;
    }
    bool isIsomorphic(string s, string t)
    {

        bool one = check(s, t);
        bool two = check(t, s);
        return one & two;
    }
};

// time complexity O(n);
// space complexity O(1)
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        vector<int> indexS(256, 0);
        vector<int> indexT(256, 0);

        for (int i = 0; i < s.size(); i++)
        {
            if (indexS[s[i]] != indexT[t[i]])
            {
                return false;
            }
            indexS[s[i]] = i + 1;
            indexT[t[i]] = i + 1;
        }
        return true;
    }
};