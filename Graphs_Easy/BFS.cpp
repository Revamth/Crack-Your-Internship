class Solution
{
public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfs(vector<vector<int>> &adj)
  {
    // Code here
    int n = adj.size();
    vector<int> adjLs[n];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        adjLs[i].push_back(j);
        adjLs[j].push_back(i);
      }
    }
    int vis[n] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      bfs.push_back(node);

      for (auto it : adj[node])
      {
        if (!vis[it])
        {
          vis[it] = 1;
          q.push(it);
        }
      }
    }
    return bfs;
  }
};