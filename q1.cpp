// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// Microsoft

class Solution
{

    int toNos(string str)
    {

        int ans{};
        int size(str.size());
        int i = size - 1, k{};

        while (i >= 0)
        {
            if (i == 0 && str[i] == '-')
                break;
            int nos = str[i] - '0';
            ans += nos * pow(10, k++);
            i--;
        }
        if (i == 0 && str[i] == '-')
            ans *= -1;
        // cout<<ans<<" ";
        return ans;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i].size() > 1 || (tokens[i].size() == 1 && (tokens[i][0] != '+' && tokens[i][0] != '-' && tokens[i][0] != '*' && tokens[i][0] != '/')))
            {
                int val = toNos(tokens[i]);
                stk.push(val);
            }
            else
            {
                int f = stk.top();
                stk.pop();
                int s = stk.top();
                stk.pop();

                int ans{};

                if (tokens[i][0] == '+')
                    ans = s + f;
                else if (tokens[i][0] == '-')
                    ans = s - f;
                else if (tokens[i][0] == '*')
                    ans = s * f;
                else
                    ans = s / f;
                stk.push(ans);
            }
        }

        return stk.top();
    }
};