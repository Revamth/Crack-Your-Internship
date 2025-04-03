class Solution
{
public:
  void func(TreeNode *root, vector<int> &inorder)
  {
    if (!root)
      return;
    if (root->left)
      func(root->left, inorder);
    inorder.push_back(root->val);
    if (root->right)
      func(root->right, inorder);
  }
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> inorder;
    func(root, inorder);
    return inorder;
  }
};