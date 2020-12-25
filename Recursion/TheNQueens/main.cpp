/*
Given an input integer n, generate all n x n boards with n non-attacking queens placed.

A queen q1 is "attacking" another queen q2 if ;
q2 sits in the same row as q1
q2 sits in the same column as q1
q2 sits in the diagonal reach of q1

Attacking Arrangement:
[
 "-Q--",
 "-Q--",
 "Q---",
 "--Q-"
]

Explanation:
- Queen in row 0 is attacking queen in row 1 column-wise.
- Queen in row 2 is attacking queen in row 1 diagonally.

Example:
Input: 4

Output:
[
 [
  "-Q--",
  "---Q",
  "Q---",
  "--Q-"
 ],
 [
  "--Q-",
  "Q---",
  "---Q",
  "-Q--"
 ]
]

Explanation: There are only 2 4x4 board arrangements of 4 non-attacking queens

Constraints:
1 <= n <= 10
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> results;
        solveNQueens(0, n, vector<int>(), results);
        return results;
    }

private:
    void solveNQueens(int row, int n, vector<int> colPlacements, vector<vector<string>> &results)
    {
        // base case
        if (row == n)
        {
            results.push_back(generateBoardFromPlacement(colPlacements, n));
            return;
        }

        for (int col = 0; col < n; col++)
        {
            colPlacements.push_back(col);
            if (isValid(colPlacements))
                solveNQueens(row + 1, n, colPlacements, results);
            colPlacements.erase(colPlacements.end() - 1);
        }
    }

    bool isValid(vector<int> &colPlacements)
    {
        int currentRow = colPlacements.size() - 1;


        for (int prevQueenRow = 0; prevQueenRow < currentRow; prevQueenRow++)
        {
            int absColDistance = abs(colPlacements.at(prevQueenRow) - colPlacements.at(currentRow));
            int rowDistance = currentRow - prevQueenRow;

            if (absColDistance == 0 || absColDistance == rowDistance)
                return false;
        }
        return true;
    }

    vector<string> generateBoardFromPlacement(vector<int> &colPlacements, int n)
    {
        vector<string> board;
        int totalItemsPlaced = colPlacements.size();

        for (int row = 0; row < totalItemsPlaced; row++)
        {
            string s = "";
            for (int col = 0; col < n; col++)
            {
                if (col == colPlacements.at(row))
                    s += "Q";
                else
                    s += "-";
            }
            board.push_back(s);
        }

        return board;
    }
};

int main()
{
    Solution NQueens;
    vector<vector<string>> ans = NQueens.solveNQueens(5);

    cout << "There is " << ans.size() << " solutions.\n";

    for (auto const& vec : ans)
    {
        for (auto const& elem : vec)
        {
            cout << elem << "\n";
        }
        cout << "\n";
    }

    return 0;
}