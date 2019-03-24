/* Remove Duplicates from Sorted List
 *
 * [Easy] [AC:42.0% 306.4K of 729.4K] [filetype:cpp]
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * Example 1:
 *
 * Input: 1->1->2
 *
 * Output: 1->2
 *
 * Example 2:
 *
 * Input: 1->1->2->3->3
 *
 * Output: 1->2->3
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
// #include "leetcode.h"
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    auto cur = head;

    while (cur && cur->next) {
      if (cur->val == cur->next->val)
        cur->next = cur->next->next;
      else
        cur = cur->next;
    }

    return head;
  }
};
