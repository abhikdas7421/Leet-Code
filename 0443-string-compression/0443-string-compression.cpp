class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int count = 1;
            int index = 0;

            for (int i = 1; i < chars.size(); i++)
            {
                if (chars[i] == chars[i - 1])
                {
                    count++;
                }
                else
                {
                    chars[index] = chars[i - 1];
                    index++;

                    if (count > 1)
                    {
                        string strCount = to_string(count);

                        for (int j = 0; j < strCount.size(); j++)
                        {
                            chars[index] = strCount[j];
                            index++;
                        }
                        count = 1;
                    }
                }
            }
            chars[index] = chars[chars.size() - 1];
            index++;

            if (count > 1)
            {
                string strCount = to_string(count);
                for (int j = 0; j < strCount.size(); j++)
                {
                    chars[index] = strCount[j];
                    index++;
                }
            }

            chars.resize(index);
            // for (int i = 0; i < chars.size(); i++)
            // {
            //     cout << chars[i];
            // }
            // cout << endl;
            return index;
        }
};