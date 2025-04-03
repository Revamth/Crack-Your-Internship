class Solution
{
public:
  bool func(TreeNode *root, int sum, int targetSum)
  {
    sum += root->val;

    if (!root->left && !root->right)
    {
      return sum == targetSum;
    }

    return (root->left && func(root->left, sum, targetSum)) ||
           (root->right && func(root->right, sum, targetSum));
  }
  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (!root)
      return false;
    int sum = 0;
    return func(root, sum, targetSum);
  }
};