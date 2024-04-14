class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int totalSize = row*col;
        
        int startingRow = 0;
        int endingRow = row-1;
        
        int startingCol = 0;
        int endingCol = col-1;
        
        int count = 0;
        vector<int> ans;
        
        while(count < totalSize) {
            
            // starting row
            for(int i = startingCol; i <= endingCol && count < totalSize; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            
            
            // ending col
            for(int i = startingRow; i <= endingRow && count < totalSize; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            
            
            // ending row
            for(int i = endingCol; i >= startingCol && count < totalSize; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            
            // starting col
            for(int i = endingRow; i >= startingRow && count < totalSize; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        
        return ans;
        
    }
};