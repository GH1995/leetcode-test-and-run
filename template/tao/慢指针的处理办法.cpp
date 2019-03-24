#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    auto fast = head, slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    /**
     * 快慢指针的处理办法
     */

    if (fast) slow = slow->next;  // odd nodes: let right half smaller
    slow = reverse(slow);
    fast = head;

    while (slow) {
      if (fast->val != slow->val) return false;
      fast = fast->next;
      slow = slow->next;
    }

    return true;
  }

  ListNode* reverse(ListNode* head) {
    if (!head) return nullptr;
    ListNode *prev = nullptr, *cur = head, *next = head->next;
    for (; cur; prev = cur, cur = next, next = next ? next->next : nullptr) {
      cur->next = prev;
    }

    return prev;
  }
};
