class Solution
{
    public:
        void solve(vector<string> &ans, int n, int open, int close, string str)
        {
           	// base case
            if (open == 0 && close == 0)
            {
                ans.push_back(str);
                return;
            }

           	// include open "("
            if (open > 0)
            {
                solve(ans, n, open - 1, close, str + '(');
            }

           	// include close ")"
            if (open < close)
            {
                solve(ans, n, open, close - 1, str + ')');
            }
        }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int open = n;
        int close = n;
        string str = "";

        solve(ans, n, open, close, str);

        return ans;
    }
};