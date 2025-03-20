class Solution
{
public:
  int subarraysDivByK(vector<int> &nums, int k)
  {
    unordered_map<int, int> prefixSumCount{{0, 1}};
    int countSubarrays = 0;
    int cumulativeSum = 0;
    for (int num : nums)
    {
      cumulativeSum = ((cumulativeSum + num) % k + k) % k;

      countSubarrays += prefixSumCount[cumulativeSum]++;
    }

    return countSubarrays;
  }
};