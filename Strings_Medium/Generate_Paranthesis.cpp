class Solution
{
public:
  void func(int n, vector<string> &ans, string curr, int open, int close)
  {
    if (close == n)
    {
      ans.push_back(curr);
      return;
    }
    if (open < n)
    {
      func(n, ans, curr + '(', open + 1, close);
    }
    if (close < open)
    {
      func(n, ans, curr + ')', open, close + 1);
    }
  }
  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    string curr = "";
    func(n, ans, curr, 0, 0);
    return ans;
  }
};