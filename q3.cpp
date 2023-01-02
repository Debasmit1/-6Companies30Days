// https://leetcode.com/problems/bulls-and-cows/description/
// Microsoft

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<int, int> s, g;

        int bull{}, cow{};

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bull++;
            }
            else
            {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }

        for (int i = 0; i <= 9; i++)
        {
            cow += min(s[i], g[i]);
        }

        string ans = to_string(bull) + 'A' + to_string(cow) + 'B';

        return ans;
    }
};