class Solution
{
public:
  bool isPossible(char first, char second)
  {
    if ((first == '(' && second == ')') ||
        (first == '{' && second == '}') || (first == '[' && second == ']'))
      return true;
    return false;
  }
  bool isValid(string s)
  {
    stack<char> st;
    for (auto it : s)
    {
      if (it == '(' || it == '{' || it == '[')
        st.push(it);
      else
      {
        if (st.empty())
          return false;
        char first = st.top();
        st.pop();
        char second = it;
        if (isPossible(first, second) == false)
          return false;
      }
    }
    if (!st.empty())
      return false;
    return true;
  }
};