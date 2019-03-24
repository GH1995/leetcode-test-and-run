适用场景

输入数据：
    递归数据结构：单链表，二叉树，集合，百分之百可用递归
    非递归数据结构：一维二维数组，字符串，图

状态转换图：
    树或图

求解目标：
    必须走到最深才能得到一个解
    对树来说，是叶子节点

---

思考步骤

1. 求路径条数，还是路径本身`path`数组存储路径
2. 求一个解还是多个解
3. 一个状态必须存储哪些数据才能完整的扩展到下一步。
4. 如何扩展状态
5. 终止条件是什么`x = nums.size() - 1`
6. 收敛条件是什么`x < nums.size()`
7. 判重
8. 加速
    - 剪枝
    - 缓存`unordered_map`

```
void dfs(type &input, type &path, type &result, int cur or gap) {
    if (数据非法) return 0;         // 终止条件 
    if (cur == input.size()) {
 // if (gap == 0) 
        将 path 放入 result 
    }

    if () return;                   // 剪枝

    for () { // 执行所有可能的扩展操作
        执行动作
        修改 path
        dfs(input, step + 1, gap--, result);
        恢复 path
    }
}
```

深搜和回溯的区别

回溯 = 深搜 + 剪枝

深搜和递归的区别

prunning 剪枝

缓存 
递归 + 缓存 = 备忘录法
