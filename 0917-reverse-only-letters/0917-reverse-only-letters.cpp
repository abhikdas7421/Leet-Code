class Solution
{
    public:
        bool isLetters(char ch)
        {
            if ((ch >= 'a' && 'z' >= ch) || (ch >= 'A' && 'Z' >= ch))
            {
                return true;
            }

            return false;
        }

        string reverseOnlyLetters(string s)
        {
            int i = 0, j = s.size() - 1;

            while (i < j)
            {

                if (isLetters(s[i]) && isLetters(s[j]))
                {
                    swap(s[i], s[j]);
                    i++;
                    j--;
                }
                else if (!isLetters(s[i]))
                {
                    i++;
                }
                else if (!isLetters(s[j]))
                {
                    j--;
                }
            }

            return s;
        }
};