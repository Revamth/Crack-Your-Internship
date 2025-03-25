class Solution
{
public:
  int reverse(int x)
  {
    long long l;
    long long rev = 0;
    while (x)
    {
      l = x % 10;
      x = x / 10;
      rev = (rev * 10) + l;
    }
    if (rev > INT_MAX || rev < INT_MIN)
      return 0;
    return rev;
  }
};