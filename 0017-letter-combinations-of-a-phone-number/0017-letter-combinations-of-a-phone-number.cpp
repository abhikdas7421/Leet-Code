class Solution
{
    public:
    
        void solve(string digits, int index, vector<string> &mapping, vector<string> &ans, string output) 
        {
            // base case
            if(index >= digits.length())
            {
                ans.push_back(output);
                return;
            }
            
            // solve 1 case, rest will handle recursion
            
            // int digit = digits[index] - '0';
            // string value = mapping[digit];
            
            string value = mapping[digits[index] - '0'];
            
            for(int i = 0; i < value.length(); i++) 
            {
                // char ch = value[i];
                solve(digits, index+1, mapping, ans, output+value[i]);
            }
        }

        vector<string> letterCombinations(string digits)
        {   
            vector<string> ans;
            if(digits.length() == 0)
            {
                return ans;
            }
            
            string output = "";
            vector<string> mapping(10);
            
            mapping[2] = "abc";
            mapping[3] = "def";
            mapping[4] = "ghi";
            mapping[5] = "jkl";
            mapping[6] = "mno";
            mapping[7] = "pqrs";
            mapping[8] = "tuv";
            mapping[9] = "wxyz";
            
            solve(digits, 0, mapping, ans, output);
            return ans;
        }
};