class Solution
{
public:
  int minMoves(vector<int> &nums)
  {
    int sum = 0;
    int minVal = INT_MAX;
    for (int num : nums)
    {
      sum += num;
      minVal = min(minVal, num);
    }

    return sum - minVal * nums.size();
  }
};