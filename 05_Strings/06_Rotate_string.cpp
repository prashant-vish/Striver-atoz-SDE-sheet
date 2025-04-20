#include <bits/stdc++.h>
using namespace std;
// brute force
// time complexity O(n^2)
// space complexity O(n^2)
class Solution
{
public:
    bool rotateString(string s, string goal)
    {

        if (s == goal)
            return true;
        if (s.size() != goal.size())
            return false;

        string copy = s;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = copy[0];
            string temp = copy.substr(1);
            temp += ch;
            copy = temp;
            if (copy == goal)
            {
                return true;
            }
        }
        return false;
    }
};

// better Approach
// time complexity O(n)
// space complexity O(1)

class Solution
{
public:
    bool reverseStr(string goal, string s, int i)
    {

        reverse(goal.begin(), goal.begin() + i);
        reverse(goal.begin() + i, goal.end());
        reverse(goal.begin(), goal.end());
        if (s == goal)
            return true;

        return false;
    }
    bool rotateString(string s, string goal)
    {

        if (s == goal)
            return true;
        if (s.size() != goal.size())
            return false;

        char ch = s[0];
        for (int i = 0; i < s.size(); i++)
        {
            if (ch == goal[i])
            {
                if (reverseStr(goal, s, i))
                    return true;
            }
        }
        return false;
    }
};

// Another approach
// Time complexity - O(n^2)
// space complexity - O(n)

class Solution
{
public:
    bool rotateString(string s, string goal)
    {

        if (s.size() != goal.size())
            return false;
        return (s + s).find(goal) != string::npos;
    }
};