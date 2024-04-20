class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> leftMax(n, 0);
        
        vector<int> rightMax(n, 0);
        
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, height[i]);
            leftMax[i] = maxi;
        }
        
        maxi = INT_MIN;
        for(int j = n-1; j >= 0; j--) {
            maxi = max(maxi, height[j]);
            rightMax[j] = maxi;
        }
        
        int trappedWater = 0;
        for(int i = 0; i < n; i++) {
            trappedWater += min(leftMax[i], rightMax[i])-height[i];
        }
        
        return trappedWater;
    }
};