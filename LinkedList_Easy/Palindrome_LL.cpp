/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
      ListNode* reverse(ListNode* head) {
          ListNode *temp = head, *prev = NULL;
          while (temp != NULL) {
              ListNode* front = temp->next;
              temp->next = prev;
              prev = temp;
              temp = front;
          }
          return prev;
      }
      bool isPalindrome(ListNode* head) {
          if (head == NULL || head->next == NULL)
              return true;
          ListNode*slow = head, *fast = head;
          while (fast != NULL && fast->next != NULL) {
              slow = slow->next;
              fast = fast->next->next;
          }
          slow = reverse(slow);
          ListNode* dummy = head;
          while (slow != NULL) {
              if (dummy->val != slow->val)
                  return false;
              dummy = dummy->next;
              slow = slow->next;
          }
          return true;
      }
  };