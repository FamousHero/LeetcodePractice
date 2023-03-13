#include <vector>

/**
 * Approach: since we a given a list of LinkedLists, we must iterate through it each time
 * until the list is full of nullptrs. We only increment the LinedList which is the smallest.
 * Since LinkedLists are represented by pointers, we can just increment the pointer of the smallest
 * ListNode to its next value.
 * 
 * NOTE: While this approach works, it is VERY UNOPTIMIZED. Other optimized solutions 
 * implement divide & conquer and Priority Queues to get O(n log k) with n = nodes and k = list size
*/


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* mergedList = new ListNode();
        ListNode* currentNode = mergedList;
        if(lists.empty()) return nullptr;
        
        int smallestIndex = -1;
        int counter = 0;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i]) ++counter;
        }
        
        while(counter > 1){
            for(int i = 0; i < lists.size(); ++i){
                if(lists[i]){
                    if(smallestIndex == -1)
                        smallestIndex = i;
                    else if(lists[i]->val < lists[smallestIndex]->val)
                        smallestIndex = i;
                }
            }
            currentNode->next = lists[smallestIndex];
            lists[smallestIndex] = lists[smallestIndex]->next;
            if(!lists[smallestIndex]) --counter;
            currentNode = currentNode->next;   
            smallestIndex = -1;
        }
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i]) currentNode->next = lists[i];
        }
        return mergedList->next;
    }
};