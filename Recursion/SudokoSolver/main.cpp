#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<char>> Board = 
{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
 {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

void PrintBoard(vector<vector<char>> &board)
{
    for (auto const& row : board)
    {
        for (auto const& col : row)
        {
            cout.width(2);
            cout << col << " ";
        }
        cout << "\n";
    }
}

class Solution
{
public:
    vector<vector<char>> solveSudoku(vector<vector<char>> board)
    {
        solveFromCell(0, 0, board);
        return board;
    }

private:
    static char EMPTY_ENTRY;

private:
    bool solveFromCell(int row, int col, vector<vector<char>> &board)
    {
        if (col == board[row].size())
        {
            col = 0;
            row++;
            if (row == board.size())
                return true;
        }

        if (board[row][col] != EMPTY_ENTRY)
            return solveFromCell(row, col+1, board);
        
        for (int i = 1; i <= board.size(); i++)
        {
            char charToPlace = static_cast<char>(i + '0');

            if (canPlaceValue(board, row, col, charToPlace))
            {
                board[row][col] = charToPlace;
                // Main Recursion
                if (solveFromCell(row, col+1, board))
                    return true;
                // Backtrack
                board[row][col] = EMPTY_ENTRY;
            }
        }

        return false;
    }
    
    bool canPlaceValue(vector<vector<char>> &board, int row, int col, char charToPlace)
    {
        // Check for column of the placement
        for (auto const& row : board)
        {
            if (row[col] == charToPlace)
                return false;
        }

        // Check for row of the placement
        for (auto const& elem : board[row])
        {
            if (elem == charToPlace)
                return false;
        }

        // Check for the region constraints - get the size of the sub-box
        int regionSize = sqrt(board.size());

        int verticvalBoxIndex = row / regionSize;
        int horizontalBoxIndex = col / regionSize;

        int topLeftOfSubBoxRow = verticvalBoxIndex * regionSize;
        int topLeftOfSubBoxCol = horizontalBoxIndex * regionSize;

        for (int r = 0; r < regionSize; r++)
        {
            for (int c = 0; c < regionSize; c++)
            {
                if (board[topLeftOfSubBoxRow + r][topLeftOfSubBoxCol + c] == charToPlace)
                    return false;
            }
        }

        return true;
    }
};

char Solution::EMPTY_ENTRY = '.';


 int main()
 {
    Solution sol;
    PrintBoard(Board);
    cout << "\n";

    vector<vector<char>> ans = sol.solveSudoku(Board);
    PrintBoard(ans);

    return 0;
 }