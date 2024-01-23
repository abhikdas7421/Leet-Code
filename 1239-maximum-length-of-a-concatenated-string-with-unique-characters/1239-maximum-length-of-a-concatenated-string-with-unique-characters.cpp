class Solution {
public:
    bool isUnique(string str1, string str2) {
        vector<int> freq(26, 0);
        
        for(auto ch : str1) {
            if(freq[ch-'a']) {
                return false;
            }
            freq[ch-'a']++;
        }
        
        for(auto ch : str2) {
            if(freq[ch-'a']) {
                return false;
            }
            freq[ch-'a']++;
        }
        
        return true;
    }
    
    /*
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
    */
    
    int solve(vector<string> &arr, int i, string temp) {
        
        if(i >= arr.size()) {
            return temp.length();
        }
        
        int include = 0;
        int exclude = 0;
        
        exclude = solve(arr, i+1, temp);
        if(isUnique(temp, arr[i])) {
            include = solve(arr, i+1, temp+arr[i]);
        }
        
        return max(include, exclude);
        
    }
    
    int maxLength(vector<string>& arr) {
        string temp = "";
        
        int ans = solve(arr, 0, temp);
        return ans;
    }
};