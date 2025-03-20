class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int j = i + 1, k = nums.size() - 1;
      while (j < k)
      {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0)
        {
          vector<int> temp = {nums[i], nums[j], nums[k]};
          res.push_back(temp);
          j++;
          k--;
          while (nums[j] == nums[j - 1] && j < k)
          {
            j++;
          }
        }
        else if (sum > 0)
          k--;
        else
          j++;
      }
    }
    return res;
  }
};