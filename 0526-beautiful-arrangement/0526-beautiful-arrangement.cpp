class Solution {
public:
    void countArrangementHelper(vector<int> &v, int &ans, int &n, int currNum) {
        // base case
        if(currNum >= n+1) {
            // for(int i = 1; i <= n; i++) {
            //     cout << v[i] << " ";
            // }
            // cout << endl;
            ++ans;
            return;
        }
        
        
        // recursion
        for(int i = 1; i <=n; i++) {
            
            if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0)) {
                v[i] = currNum;
                countArrangementHelper(v, ans, n, currNum+1);
                
                v[i] = 0; // backtracking
            }
        }
    }
    
    int countArrangement(int n) {
        vector<int> v(n+1, 0);
        int ans = 0;
        
        countArrangementHelper(v, ans, n, 1);
        
        return ans;
        
    }
};