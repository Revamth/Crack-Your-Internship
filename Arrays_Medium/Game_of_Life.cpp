class Solution
{
public:
  void gameOfLife(vector<vector<int>> &board)
  {
    int n = board.size();
    int m = board[0].size();
    vector<int> dx = {-1, -1, -1, 0, +1, +1, +1, 0};
    vector<int> dy = {-1, 0, +1, +1, +1, 0, -1, -1};
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int count = 0;
        for (int k = 0; k < 8; k++)
        {
          int crow = i + dx[k];
          int ccol = j + dy[k];

          if (crow >= 0 && crow < n && ccol >= 0 && ccol < m &&
              abs(board[crow][ccol]) == 1)
            count++;
        }
        if (board[i][j] == 1 && (count < 2 || count > 3))
          board[i][j] = -1;

        if (board[i][j] == 0 && count == 3)
          board[i][j] = 2;
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (board[i][j] >= 1)
          board[i][j] = 1;
        else
          board[i][j] = 0;
      }
    }
  }
};