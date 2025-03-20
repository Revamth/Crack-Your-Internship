class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int n = height.size();
    int low = 0, high = n - 1;
    int maxi = 0;
    while (low <= high)
    {
      int minheight = min(height[low], height[high]);
      maxi = max(maxi, (high - low) * minheight);

      if (minheight == height[low])
        low++;
      else
        high--;
    }
    return maxi;
  }
};