
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        if(n ==1 && head->next == nullptr)
        {
            head = head->next;
            delete temp1;
            return head;    
        }
        while(n)
        {
            temp1 = temp1->next;
            --n;
        }
        if(temp1 == nullptr)
        {
            head = temp2->next;
            delete temp2;
            return head;
        }
        while(temp1->next)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1 = temp2->next;
        temp2->next = temp2->next->next;
        delete temp1;
        return head;
    }
};