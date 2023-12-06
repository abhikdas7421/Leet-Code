class Solution
{
    public:

        unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftDiagonalCheck;
    unordered_map<int, bool> bottomLeftDiagonalCheck;

    void storeSoln(vector<vector < char>> &board, int n, vector<vector < string>> &ans)
    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string output = "";
            for (int j = 0; j < n; j++)
            {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(vector<vector < char>> &board, int n, int row, int col)
    {
       	// check : Can I put queen in current cell or not

       	// T.C -> O(n);
        /*// check left row
            int i = row;
            int j = col;
            while (j >= 0)
            {
                if (board[i][j] == 'Q')
                {
                    return false;
                }
                j--;
            }

           	// check upper left diagonal
            i = row;
            j = col;
            while (i >= 0 && j >= 0)
            {
                if (board[i][j] == 'Q')
                {
                    return false;
                }
                i--;
                j--;
            }

           	// check lower left diagonal
            i = row;
            j = col;
            while (i < n && j >= 0)
            {
                if (board[i][j] == 'Q')
                {
                    return false;
                }
                i++;
                j--;
            } */

       	// T.C -> O(1);
       	// check left row
        if (rowCheck[row] == true)
        {
            return false;
        }

       	// check upper left diagonal
        if (upperLeftDiagonalCheck[n - 1 + col - row] == true)
        {
            return false;
        }

       	// check lower left diagonal
        if (bottomLeftDiagonalCheck[row + col] == true)
        {
            return false;
        }

        return true;
    }

    void solve(vector<vector < char>> &board, int col, int n, vector<vector < string>> &ans)
    {
       	// base case
        if (col >= n)
        {
            storeSoln(board, n, ans);
            return;
        }

       	// solve 1 case, baaki recursion will handle

        for (int row = 0; row < n; row++)
        {
            if (isSafe(board, n, row, col))
            {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagonalCheck[n - 1 + col - row] = true;
                bottomLeftDiagonalCheck[row + col] = true;

               	// recursion get the soln
                solve(board, col + 1, n, ans);

               	// backtracking
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagonalCheck[n - 1 + col - row] = false;
                bottomLeftDiagonalCheck[row + col] = false;
            }
        }
    }

    vector<vector < string>> solveNQueens(int n)
    {
        vector<vector < char>> board(n, vector<char> (n, '.'));
        int col = 0;
        vector<vector < string>> ans;
        solve(board, col, n, ans);
        
        return ans;
    }
};