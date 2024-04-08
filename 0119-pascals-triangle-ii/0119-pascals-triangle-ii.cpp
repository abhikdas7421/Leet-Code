class Solution {
public:
    // Approach:- 1 | S.C:- O(n^2)
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal(rowIndex+1);
        
        for(int i = 0; i <= rowIndex; i++) {
            pascal[i].assign(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
        }
        
        return pascal[rowIndex];
    }
};