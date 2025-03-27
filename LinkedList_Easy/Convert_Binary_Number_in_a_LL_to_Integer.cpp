class Solution
{
public:
  int getDecimalValue(ListNode *head)
  {
    int len = 0;
    ListNode *curr = head;
    while (curr != NULL)
    {
      curr = curr->next;
      len++;
    }
    len = len - 1;
    curr = head;
    int ans = 0;
    while (curr != NULL)
    {
      ans += curr->val * pow(2, len);
      len = len - 1;
      curr = curr->next;
    }
    return ans;
  }
};