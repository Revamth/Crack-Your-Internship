class Solution
{
public:
  TreeNode *invertTree(TreeNode *root)
  {
    if (!root)
      return nullptr;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *top = q.front();
      q.pop();

      swap(top->left, top->right);

      if (top->left)
        q.push(top->left);
      if (top->right)
        q.push(top->right);
    }
    return root;
  }
};