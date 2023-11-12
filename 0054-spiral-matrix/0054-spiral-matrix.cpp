class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int total_size = rows*cols;

        int count = 0;

        int startingRow = 0;
        int endingRow = rows-1;
        int startingCol = 0;
        int endingCol = cols-1;

        while(count < total_size) {
            // starting row
            for(int i = startingCol; i <= endingCol && count < total_size; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;


            // ending col
            for(int i = startingRow; i <= endingRow && count < total_size; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;


            // ending row
            for(int i = endingCol; i >= startingCol && count < total_size; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;


            // starting col
            for(int i = endingRow; i >= startingRow && count < total_size; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
        
    }
};