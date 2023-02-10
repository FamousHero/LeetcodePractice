
//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* prev = head;
        ListNode* curr = prev->next;
       
        while(curr)
        {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            curr = prev->next;
            
        }
        return head;
    }
};