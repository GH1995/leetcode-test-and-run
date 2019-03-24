#include <iostream>
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

unordered_set<Node *> visited;
// Recurive DFS
void DFS(Node *node) {
  printf("%d\n", node->val);
  visited.insert(node);
  for (auto next : node->neighbors) {
    if (visited.find(next) == visited.end()) {
      DFS(next);
    }
  }
}
/**
 * 首先写递归版本的DFS, DFS就是一条路走到底, 不撞南墙不回头,
 * 所以递归写起来很自然: 每到一个节点, 标记其已经访问过了,
 * 然后对于邻居里面没有访问的节点继续递归进行DFS.
 *
 * 虽然这个算法很短, 但是它非常重要,
 * 回溯算法(backtracking)其实就相当于在问题的求解域做一个dfs.
 * 另外拓扑排序也是基于递归dfs进行一点点修改.
 */

// Non-recurive DFS
void Non_recurive_DFS(Node *start) {
  stack<Node *> s;
  s.push(start);

  visited.insert(start);
  while (!s.empty()) {
    auto cur = s.top();
    s.pop();
    printf("%d\n", cur->val);
    for (auto next : cur->neighbors) {
      if (visited.find(next) == visited.end()) {
        s.push(next);
        visited.insert(next);  // mark node as visited when adding to stack
      }
    }
  }
}

/**
 * 非递归版本的dfs同样很重要, 因为毕竟非递归的版本效率高一些,
 * 另外这个算法和bfs非常相似, 只不过把队列queue换成了栈stack而已:
 *
 * 同样要注意的一点就是在把一个节点入栈的时刻就将其标记为已访问.
 *
 */

// (for tree) DFS with depth
/**
 * 和上次bfs一样, 对于树而言, 在dfs搜索的过程中也可以记录该节点所在的depth.
 *
 * 非递归版本的程序就是用一个和上面s平行的栈记录深度,
 * 程序和"BFS with distance"很像.
 * 递归版本只要在函数签名里加上一个depth的参数即可. 这两个实现都很简单,
 * 就不写了.
 * 注意这个只对于树有意义, 对一个图而言没有depth一说...
 */

// DFS for binary tree: preorder traversal
/**
 * dfs另一个有用的性质是: 对于二叉树而言,
 * dfs得到的节点顺序正是其前序遍历(preorder traversal)的顺序.
 *
 * 其实前序遍历的定义就相当于是一个递归版本的dfs了:
 * [preorder(node)] = node.val + [preorder(node.left)] + [preorder(node.right)]
 */

// DFS with path
/**
 * 如果在访问到某一个节点的时候想同时获得到该点的路径, 其实也不麻烦.
 *
 * 对于递归版本的dfs而言, 可以在参数里面用一个List记录到当前节点的路径.
 *
 * 非递归的版本的话... 貌似不是很trival, 需要对stack做好维护,
 * 可能需要一个hashmap什么的... 以后有空了再写写.
 */

// Cycle Detection
/**
 *  v(1)     u(1)
 *
 * 判断一个有向图是否存在回路是一个非常重要的问题, 简单修改dfs就可以做到了.
 * 在递归版本的dfs里, 我们对每一个点改为三种标记:
 *  - 未访问过(0)
 *  - 正在访问其邻居节点(1),
 *  - 已经访问完该节点以及所有该节点可以到达的节点(2).
 * 什么时候会出现回路呢? 就是当前节点v的一个邻居u的状态为1的时候.
 *
 * 因为该节点状态为1, 即还没有把它以后的节点全部遍历,
 * 所以当前节点v肯定可以从u到达, 而现在又可以从v到达u, 所以构成一个回路.
 *
 * 为了表示一个节点的三种状态, 我们把visited的定义改一下, 定义为一个hashmap:
 * HasheMap<GraphNode, Boolean> visited = new HasheMap<GraphNode, Boolean>();
 *  - 节点不在visited表示还未访问过
 *  - 节点对应为false表示正在访问
 *  - 节点对应为true表示已经访问该节点以及所有可以从它到达的节点
 */

unordered_map<Node *, bool> visited2;
void Cycle_Detection(Node *node) {
  visited2.insert({node, false});
  for (auto next : node->neighbors) {
    if (visited2.find(next) == visited2.end()) {
      Cycle_Detection(next);
    } else if (visited2[next] == false) {
      printf("Cycle detected!\n");
    }
  }  // now all touchable nodes from node are visited
  visited2.insert({node, true});
}

// Topology Sort
/**
 * 维护一个计数器K(初始化为n=所有节点数),
 * 每当一个点已经遍历完毕(所有通过这个点可以到达的点都已经被走过)以后,
 * 就把这个点的顺序设为K, 同时减少K.
 *
 * 就用一个HashMap来为每个节点关联一个序号好了:
 * HasheMap<GraphNode, Integer> order = new HasheMap<GraphNode, Integer>();
 */

unordered_map<Node *, int> order;
int K = 100;  // n = 100 所有节点数
void Topo(Node *nd) {
  for (auto next : nd->neighbors) {
    if (visited.find(next) == visited.end()) {
      Topo(next);
    }
  }  // all touchable nodes from nd as visited
  order.insert({nd, K--});
}
