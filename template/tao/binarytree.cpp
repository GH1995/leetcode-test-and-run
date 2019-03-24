#include <algorithm>
#include <cctype>
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
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int treesize(TreeNode* root) {
  if (!root) return 0;
  return treesize(root->left) + treesize(root->right) + 1;
}

int kthSmallest(TreeNode* root, int k) {
  auto l = treesize(root->left);

  if (l >= k)
    return kthSmallest(root->left, k);
  else if (l + 1 < k)
    return kthSmallest(root->right, k - 1 - l);
  else
    return root->val;
}
