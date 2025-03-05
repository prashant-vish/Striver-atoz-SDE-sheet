#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++)
        {

            vector<int> vec;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    vec.push_back(1);
                }
                else
                {
                    int x = ans[i - 1][j] + ans[i - 1][j - 1];
                    vec.push_back(x);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};