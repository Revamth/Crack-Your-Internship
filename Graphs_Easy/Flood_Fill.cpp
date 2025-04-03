class Solution
{
public:
  bool isValid(int row, int col, int n, int m)
  {
    return (row >= 0 && row < n && col >= 0 && col < m);
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color)
  {
    int n = image.size();
    int m = image[0].size();

    int intialcolor = image[sr][sc];
    if (intialcolor == color)
      return image;
    image[sr][sc] = color;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, -1, 0, +1};
      for (int i = 0; i < 4; i++)
      {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (isValid(nrow, ncol, n, m) &&
            image[nrow][ncol] == intialcolor)
        {
          image[nrow][ncol] = color;
          q.push({nrow, ncol});
        }
      }
    }
    return image;
  }
};