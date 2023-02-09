
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* currNode = head;
        int carry = 0;
        while(l1 && l2){
            int temp = carry + l1->val + l2->val;
            currNode->next = new ListNode(temp%10);
            currNode = currNode->next;
            carry = temp/10;            
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int temp = carry + l1->val;
            currNode->next = new ListNode(temp%10);
            currNode = currNode->next;
            carry = temp/10;            
            l1 = l1->next;
            
        }
        while(l2){
            int temp = carry + l2->val;
            currNode->next = new ListNode(temp%10);
            currNode = currNode->next;
            carry = temp/10;            
            l2 = l2->next;
            
        }
        if(carry)
            currNode->next = new ListNode(1);
        return head->next;
    }
};