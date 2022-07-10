/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][9] = {0};
        int column[9][9] = {0};
        int sbox[9][9] = {0};
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[j].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int s = board[i][j] - '1'; //  避免overflow
                    int sbox_index = i / 3 * 3 + j / 3;
                    if(row[i][s]||column[j][s]||sbox[sbox_index][s]) return false;
                    row[i][s]=column[j][s]=sbox[sbox_index][s] = 1;
                    
                }
            }
        }
        return true;
    }
};
// @lc code=end
