class Solution
{
public:
  void func(TreeNode *root, vector<string> &ans, string curr)
  {
    if (!root)
      return;

    curr += "->" + to_string(root->val);

    if (!root->left && !root->right)
    {
      ans.push_back(curr);
      return;
    }

    if (root->left)
      func(root->left, ans, curr);
    if (root->right)
      func(root->right, ans, curr);
  }

  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> ans;
    if (!root)
      return ans;

    string curr = to_string(root->val);
    if (!root->left &&
        !root->right)
    {
      ans.push_back(curr);
      return ans;
    }

    func(root->left, ans, curr);
    func(root->right, ans, curr);

    return ans;
  }
};
