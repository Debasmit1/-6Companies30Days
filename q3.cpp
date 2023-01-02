// https://leetcode.com/problems/bulls-and-cows/description/

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.size();
        int cntB{}, cntC{};
        map<int, int> mp1;
        map<int, int> mp2;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                cntB++;
            else
            {
                mp1[secret[i] - '0']++;
                mp2[guess[i] - '0']++;
            }
        }
        for (auto it : mp1)
        {
            if (mp2.find(it.first) != mp2.end())
                cntC += min(mp2[it.first], it.second);
        }
        string s = "";
        s = to_string(cntB) + "A" + to_string(cntC) + "B";
        return s;
    }
};