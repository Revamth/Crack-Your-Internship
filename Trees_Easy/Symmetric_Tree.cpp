class Solution
{
public:
  bool func(TreeNode *root1, TreeNode *root2)
  {
    if (!root1 && !root2)
      return true;
    if (!root1 || !root2)
      return false;
    if (root1->val != root2->val)
      return false;
    return func(root1->left, root2->right) &&
           func(root1->right, root2->left);
  }
  bool isSymmetric(TreeNode *root)
  {
    if (!root)
      return true;

    return func(root->left, root->right);
  }
};