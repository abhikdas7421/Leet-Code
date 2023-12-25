class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char value) {
        for(int i = 0; i < 9; i++) {
            // row check
            if(board[row][i] == value)
                return false;
            
            
            // col check
            if(board[i][col] == value)
                return false;
            
            
            // 3*3 board check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == value)
                return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        
        int n = 9;
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                
                if(board[row][col] == '.') {
                    
                    for(int val = '1'; val <= '9'; val++) {
                        
                        if(isSafe(board, row, col, val)) {
                            
                            board[row][col] = val;
                            // bool isSolnPoss = solve(board);
                            
                            if(solve(board)) {
                                return true;
                            }
                            else {
                                board[row][col] = '.';
                            }
                            
                            
                        }
                    }
                    
                    return false;
                }
                
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};