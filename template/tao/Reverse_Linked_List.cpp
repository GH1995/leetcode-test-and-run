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

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* reverse(ListNode* head) {
    if (!head) return nullptr;
    ListNode *prev = nullptr, *cur = head, *next = head->next;
    for (; cur; prev = cur, cur = next, next = next ? next->next : nullptr) {
      cur->next = prev;
    }

    return prev;
  }
}
