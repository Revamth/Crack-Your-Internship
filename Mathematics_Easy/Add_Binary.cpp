class Solution
{
public:
  string addBinary(string a, string b)
  {
    int n = a.size();
    int m = b.size();
    int i = n - 1, j = m - 1;
    int carry = 0;
    string ans = "";

    while (i >= 0 || j >= 0 || carry)
    {
      int val = carry;
      if (i >= 0)
        val += (a[i--] - '0');
      if (j >= 0)
        val += (b[j--] - '0');

      ans += to_string(val % 2);
      carry = val / 2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
