#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findWord(vector<vector<char>> &board, int i, int j, int row, int col, string word, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || j < 0 || i == row || j == col || board[i][j] != word[index] || board[i][j] == '!')
            return false;

        char ch = board[i][j];
        board[i][j] = '!';
        bool left = findWord(board, i - 1, j, row, col, word, index + 1);
        bool top = findWord(board, i, j - 1, row, col, word, index + 1);
        bool right = findWord(board, i + 1, j, row, col, word, index + 1);
        bool bottom = findWord(board, i, j + 1, row, col, word, index + 1);
        board[i][j] = ch;

        return left || top || right || bottom;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int row = board.size();
        int col = board[0].size();
        if (word.size() > row * col)
            return false;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (findWord(board, i, j, row, col, word, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};