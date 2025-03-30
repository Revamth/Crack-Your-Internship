class Solution
{
public:
  int rangeSumBST(TreeNode *root, int low, int high)
  {
    if (!root)
      return 0;
    queue<TreeNode *> q;
    q.push(root);
    int sum = 0;

    while (!q.empty())
    {
      TreeNode *front = q.front();
      q.pop();
      if (front->val >= low && front->val <= high)
        sum += front->val;

      if (front->left && front->val > low)
        q.push(front->left);
      if (front->right && front->val < high)
        q.push(front->right);
    }
    return sum;
  }
};