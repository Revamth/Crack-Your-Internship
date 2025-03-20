class Solution
{
public:
  int findMinDiff(vector<int> &a, int m)
  {
    // code here
    sort(a.begin(), a.end());
    int mini = INT_MAX;
    for (int i = 0; i + m - 1 < a.size(); i++)
    {
      int diff = a[i + m - 1] - a[i];
      mini = min(mini, diff);
    }
    return mini;
  }
};