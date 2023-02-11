#include <unordered_set>
//Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> address;
        while(head != nullptr)
        {
            if(address.count(head) != 0)
                return true;
            address.insert(head);
        }
        return false;
    }
};