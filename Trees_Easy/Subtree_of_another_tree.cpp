class Solution
{
public:
  bool isSame(TreeNode *root1, TreeNode *root2)
  {
    if (!root1 && !root2)
      return true;
    if (!root1 || !root2)
      return false;
    if (root1->val != root2->val)
      return false;

    return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    if (!root)
      return false;
    if (!subRoot)
      return true;

    if (isSame(root, subRoot))
      return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};
