class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle(numRows);
        
        for(int i = 0; i < numRows; i++) {
            pascalTriangle[i].assign(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                pascalTriangle[i][j] = pascalTriangle[i-1][j] + pascalTriangle[i-1][j-1];
            }
        }
        
        return pascalTriangle;
        
        
    }
};