/* Remove Duplicates from Sorted List II
 * 
 * [Medium] [AC:32.3% 170.8K of 528.8K] [filetype:cpp]
 * 
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * Input: 1->2->3->3->4->4->5
 * 
 * Output: 1->2->5
 * 
 * Example 2:
 * 
 * Input: 1->1->1->2->3
 * 
 * Output: 2->3
 * 
 * [End of Description] */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "leetcode.h"
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        auto prev = &dummy;
        auto cur = head;
        
        while (cur) {
            bool duplicated = false;
            
            // å é¤ cur .... cur-1 ä¸­çéå¤åç´ 
            while (cur->next && cur->val == cur->next->val) {
                duplicated = true;
                
                auto temp = cur;
                cur = cur->next;
                delete temp;
            }
            
            // å¤æ­ä¸é¢çä»£ç æ¯å¦æ§è¡äº
            if (duplicated) { // å é¤éå¤çæåä¸ä¸ªåç´ 
                auto temp = cur;
                cur = cur->next;
                delete temp;
                continue;
            }
            
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
        }
        
        prev->next = cur;
        return dummy.next;
    }
};
