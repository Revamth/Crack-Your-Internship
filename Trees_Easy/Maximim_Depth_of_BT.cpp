class Solution
{
public:
  int height(TreeNode *root)
  {
    if (!root)
      return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
  }
  int maxDepth(TreeNode *root)
  {
    if (!root)
      return 0;
    return height(root);
  }
};