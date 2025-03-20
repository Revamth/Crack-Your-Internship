class Solution
{
public:
  int maxScore(vector<int> &cards, int k)
  {
    int lsum = 0, rsum = 0;
    int n = cards.size();
    for (int i = 0; i < k; i++)
      lsum += cards[i];
    int right = n - 1;
    int maxi = lsum;
    for (int i = k - 1; i >= 0; i--)
    {
      lsum -= cards[i];
      rsum += cards[right];
      right--;
      maxi = max(maxi, lsum + rsum);
    }
    return maxi;
  }
};