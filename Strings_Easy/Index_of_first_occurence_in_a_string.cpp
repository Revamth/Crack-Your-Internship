class Solution
{
public:
  bool issame(string s, int ind, string t)
  {
    int n = s.size();
    int m = t.size();
    if (n - ind + 1 < m)
      return false;
    int i = ind + 1, j = 1;
    while (j < m)
    {
      if (s[i] == t[j])
      {
        i++;
        j++;
      }
      else
        return false;
    }
    return true;
  }
  int strStr(string s, string t)
  {
    int n = s.size();
    int m = t.size();

    for (int i = 0; i < n - m + 1; i++)
    {
      if (s[i] == t[0])
      {
        if (issame(s, i, t))
          return i;
      }
    }

    return -1;
  }
};