/* Permutations
 *
 * [Medium] [AC:53.7% 346.6K of 645.4K] [filetype:cpp]
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 * Input: [1,2,3]
 *
 * Output:
 *
 * [
 *
 *   [1,2,3],
 *
 *   [1,3,2],
 *
 *   [2,1,3],
 *
 *   [2,3,1],
 *
 *   [3,1,2],
 *
 *   [3,2,1]
 *
 * ]
 *
 * [End of Description] */
// #include "leetcode.h"
class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> path;

    backtrack(result, path, nums);

    return result;
  }

  void backtrack(vector<vector<int>> &result, vector<int> &path,
                 vector<int> &nums) {
    if (path.size() == nums.size())
      result.push_back(path);
    else {  // 如果元素没满，就不断地往里面加元素
      for (int i = 0; i < nums.size();
           ++i) {  //加元素是从nums 0->n-1加，只要检测有没有包含就行
        if (find(path.begin(), path.end(), nums[i]) != path.end())
          continue;  // element already exists, skip
        path.push_back(nums[i]);
        backtrack(result, path, nums);
        path.pop_back();
      }
    }
  }
};

// int main(void) {
  // vector<int> v = {1, 2, 3};
  // auto s = Solution().permute(v);
  // print_2_vector(s);
  // return 0;
// }
