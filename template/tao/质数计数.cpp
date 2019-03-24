#include <algorithm>
#include <bitset>
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
 *
 *  f(x) = x^2 - num
 *
 *  f'(x_0) = \lim_{x \to x_0} \frac{f(x) - f(x_0)}{x - x_0}
 *
 *  f(x_0) = 0
 *  f'(x_0) = \frac{f(x) - f(x_0)}{x - x_0}
 *          = \frac{f(x)}{x - x_0}
 *
 *  \frac{f(x)}{f'(x)} = x - x_0
 *
 *  x_0 = x - \frac{f(x)}{f'(x)}
 *
 *  f'(x) = 2x
 *  x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}
 *          = x_n - \frac{x_n^2 - num}{2x_n}
 *          = \frac{1}{2}(x_n + \frac{n}{x_k})
 *
 */

class Solution {
 public:
  int countPrimes(int n) {
    vector<char> composer(n, '0');
    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (composer[i] == '0') {
        count++;
        for (int j = 2; i * j < n; ++j) composer[i * j] = '1';
      }
    }

    return count;
  }
};

int main(void) {
  cout << Solution().countPrimes(10) << endl;
  return 0;
}
