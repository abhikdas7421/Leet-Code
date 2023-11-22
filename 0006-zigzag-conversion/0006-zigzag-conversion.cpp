class Solution
{
    public:
        string convert(string s, int numRows)
        {
            if(numRows == 1) return s;
            
            string ans = "";
            vector<string> p(numRows);

            bool topToBottom = true;

            int i = 0;
            int j = 0;
            while (i < s.size())
            {
                if (topToBottom)
                {
                    if (j < numRows)
                    {
                        p[j].push_back(s[i]);
                        j++;
                        i++;
                    }
                    else
                    {
                        j -= 2;
                        topToBottom = false;
                    }
                }
                else
                {
                    if (j >= 0)
                    {
                        p[j].push_back(s[i]);
                        j--;
                        i++;
                    }
                    else
                    {
                        j += 2;
                        topToBottom = true;
                    }
                }
            }
            for(auto str:p) {
                ans += str;
            }
            
            return ans;
        }
};