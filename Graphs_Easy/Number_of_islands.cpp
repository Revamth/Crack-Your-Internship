class Solution
{
public:
  void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
  {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    int drow[] = {-1, 1, 0, 0};
    int dcol[] = {0, 0, -1, 1};

    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            grid[nrow][ncol] == '1' && !vis[nrow][ncol])
        {
          vis[nrow][ncol] = 1;
          q.push({nrow, ncol});
        }
      }
    }
  }

  int numIslands(vector<vector<char>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vis[i][j] && grid[i][j] == '1')
        {
          cnt++;
          bfs(i, j, grid, vis);
        }
      }
    }
    return cnt;
  }
};
