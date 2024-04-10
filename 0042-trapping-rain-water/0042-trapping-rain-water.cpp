class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        
        int lmax = INT_MIN, rmax = INT_MIN, ans = 0;
        
        while(l < r) {
            lmax = max(height[l], lmax);
            rmax = max(height[r], rmax);
            
            if(lmax < rmax) {
                ans += (lmax-height[l++]);
            }
            else {
                ans += (rmax-height[r--]);
            }
        }
        
        return ans;
    }
};