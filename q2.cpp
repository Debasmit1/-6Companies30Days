// https://leetcode.com/problems/combination-sum-iii/

class Solution
{
public:
    vector<vector<int>> ans;
    void f(int k, int n, int val, int i, vector<int> &ds)
    {
        if (i > 10 or k < 0)
            return;
        if (k == 0 and val == n)
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(i);
        f(k - 1, n, val + i, i + 1, ds);
        ds.pop_back();
        f(k, n, val, i + 1, ds);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> ds;
        f(k, n, 0, 1, ds);
        return ans;
    }
};