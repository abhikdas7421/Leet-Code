class Solution {
public:
    bool isValidCell(vector<vector<char>>& board, int row, int col) {
        vector<int> entireRow(10, 0);
        vector<int> entireCol(10, 0);
        vector<int> smallBoard(10, 0);
        
        for(int i = 0; i < 9; i++) {
            // row
            if(board[row][i] != '.') {
                int val = board[row][i] - '0';
                
                if(entireRow[val] >= 1) {
                    return false;
                }
                entireRow[val]++;
            }
            
            
            // col
            if(board[i][col] != '.') {
                int val = board[i][col] - '0';
                
                if(entireCol[val] >= 1) {
                    return false;
                }
                entireCol[val]++;
            }
            
            
            // small board
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] != '.') {
                int val = board[3*(row/3) + i/3][3*(col/3) + i%3] - '0';
                
                if(smallBoard[val] >= 1) {
                    return false;
                }
                smallBoard[val]++;
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        for(int row = 0; row < 9; row++) {
            
            for(int col = 0; col < 9; col++) {
                
                if(!isValidCell(board, row, col)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};