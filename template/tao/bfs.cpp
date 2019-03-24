#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  vector<Node *> neighbors;

  Node() {}

  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// BFS for trees/graphs
void BFS(Node *start) {
  queue<Node *> q;
  q.push(start);
  unordered_set<Node *> visited;
  visited.insert(start);

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    printf("%d\n", cur->val);

    for (auto next : cur->neighbors) {
      if (visited.find(next) == visited.end()) {
        q.push(next);
        visited.insert(next);  // mark node as visited when adding to queue!
      }
    }
  }
}

// BFS with distance
/**
 * 在BFS的同时我们可以记录从start节点到当前node的距离,
 * 方法是把一个距离信息同时入队(封装一个Pair<GraphNode, Integer>),
 * 或者使用一个与queue平行的队列保存距离信息.
 */

// BFS "by layer"
void BFS_by_layer(Node *start) {
  vector<Node *> q;
  unordered_set<Node *> visited;
  q.push_back(start);
  visited.insert(start);

  while (!q.empty()) {
    vector<Node *> newq;
    for (auto cur : q) {  // deal with all nodes in the queue
      printf("%d\n", cur->val);
      for (auto next : cur->neighbors) {
        if (visited.find(next) == visited.end()) {
          newq.push_back(next);
          visited.insert(next);
        }
      }
    }
    printf("\n");
    q = newq;
  }
}
