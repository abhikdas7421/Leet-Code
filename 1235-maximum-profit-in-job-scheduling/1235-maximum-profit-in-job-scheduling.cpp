class Solution {
public:
    int solve(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int i, int prevEndTime, vector<int> &dp) {
        // base case
        if(i >= profit.size()) {
            return 0;
        }
        
        if(dp[i] != -1) {
            return dp[i];
        }
        
        
        
        int index = lower_bound(startTime.begin(), startTime.end(), endTime[i])-startTime.begin();
        
        // pick
        int pick = profit[i] + solve(startTime, endTime, profit, index, endTime[i], dp);
        // cout << pick << endl;
        
        
        // not pick
        int notPick = solve(startTime, endTime, profit, i+1, prevEndTime, dp);
        
        dp[i] = max(pick, notPick);
        return dp[i];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs(n);
        
         for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        
        for(int i = 0; i < n; i++) {
            startTime[i] = get<0>(jobs[i]);
            endTime[i] = get<1>(jobs[i]);
            profit[i] = get<2>(jobs[i]);
        }
        
        vector<int> dp(n, -1);
        return solve(startTime, endTime, profit, 0, 0, dp);
    }
};