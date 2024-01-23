class Solution {
public:
    bool isUnique(string str) {
        sort(str.begin(), str.end());
        for(int i = 1; i < str.length(); i++) {
            if(str[i] == str[i-1]) {
                return false;
            }
        }
        return true;
    }
    
    void solve(vector<string>& arr, int i, string& subSeq, int& ans) {
        // base case
        if(i >= arr.size()) {
            if(subSeq.size() > ans) {
                ans = subSeq.size();
                
                // cout << ans << endl;
                // cout << subSeq << endl;
            }
            return;
        }
        
        // not pick 
        solve(arr, i+1, subSeq, ans);
        
        // pick
        
        string temp = subSeq+arr[i];
        if(isUnique(temp)) {
            solve(arr, i+1, temp, ans);
            
        }
        else {
            solve(arr, i+1, subSeq, ans);
        }
        
       
    }
    
    int maxLength(vector<string>& arr) {
        string subSeq;
        int ans = 0;
        solve(arr, 0, subSeq, ans);
        cout << "Ans: " <<  ans;
        
        return ans;
    }
};