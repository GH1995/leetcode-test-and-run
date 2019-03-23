#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() {}

  Node(int _val, Node* _left, Node* _right, Node* _next) {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};

template <typename T>
void print_2_vector(vector<vector<T>>& a) {
  if (a.empty()) cout << "EMPTY PARAMETER" << endl;

  for (auto i = 0; i < a.size(); ++i) {
    if (a[i].empty()) {
      printf("a[%d] is empty\n", i);
      continue;
    }

    printf("a[%d]: ", i);

    for (auto j = 0; j < a[i].size(); ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

template <typename Out>
void split(const string& s, char delim, Out result) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    *(result++) = item;
  }
}

vector<string> split(const string& s, char delim) {
  vector<string> elems;
  split(s, delim, back_inserter(elems));
  return elems;
}

template <typename T>
void print_1_vector(vector<T>& a) {
  if (a.empty()) cout << "EMPTY PARAMETER" << endl;

  copy(a.begin(), a.end(), ostream_iterator<T>(cout, " "));
}
