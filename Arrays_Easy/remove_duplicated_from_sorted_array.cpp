class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    int i = 0;
    int cnt = 1;
    for (int j = 1; j < n; j++)
    {
      if (nums[i] != nums[j])
      {
        nums[i + 1] = nums[j];
        i++;
        cnt++;
      }
    }
    return cnt;
  }
};