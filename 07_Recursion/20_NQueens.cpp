#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> answer;
    bool isSafe(vector<string> &ans, int n, int row, int col)
    {

        for (int i = row - 1; i >= 0; i--)
        {
            if (ans[i][col] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (ans[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (ans[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void addQueens(vector<string> &ans, int n, int row)
    {
        if (row == n)
        {
            answer.push_back(ans);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(ans, n, row, col))
            {
                ans[row][col] = 'Q';
                addQueens(ans, n, row + 1);
                ans[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {

        vector<string> ans(n);

        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = 0; j < n; j++)
            {
                s = s + ".";
            }
            ans[i] = s;
        }
        addQueens(ans, n, 0);

        return answer;
    }
};