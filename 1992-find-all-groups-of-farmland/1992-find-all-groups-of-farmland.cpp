class Solution {
public:
    int di[4] = {1, 0, 0, -1};
    int dj[4] = {0, 1, -1, 0};
    
    void dfs(vector<vector<int>>& land, int i, int j, vector<int>& v) {
        if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || land[i][j] <= 0) {
            return;
        }
        
        land[i][j] = -1;
        
        if(v.empty()) {
            v.push_back(i);
            v.push_back(j);
            v.push_back(i);
            v.push_back(j);
        }
        else if(v[0] >= i && v[1] >= j) {
            v[0] = i;
            v[1] = j;
        }
        else if(v[2] <= i && v[3] <= j) {
            v[2] = i;
            v[3] = j;
        }
        
        for(int k = 0; k < 4; k++) {
            dfs(land, i+di[k], j+dj[k], v);
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 1) {
                    vector<int> v;
                    dfs(land, i, j, v);
                    ans.push_back(v);
                }
            }
        }
        
        return ans;
    }
};