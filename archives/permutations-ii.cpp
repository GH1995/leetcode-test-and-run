/* Permutations II
 *
 * [Medium] [AC:39.4% 225K of 571.6K] [filetype:cpp]
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 * Input: [1,1,2]
 *
 * Output:
 *
 * [
 *
 *   [1,1,2],
 *
 *   [1,2,1],
 *
 *   [2,1,1]
 *
 * ]
 *
 * [End of Description] */
#include "leetcode.h"
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> path;

    sort(nums.begin(), nums.end());
    deque<bool> visited(nums.size(), false);

    backtrack(result, path, nums, visited);

    return result;
  }

  void backtrack(vector<vector<int>> &result, vector<int> &path,
                 vector<int> &nums, deque<bool> &visited) {
    if (path.size() == nums.size())
      result.push_back(path);
    else {
      for (int i = 0; i < nums.size(); ++i) {
        if (visited[i]  // 该数字已经用过
            || (i > 0 && nums[i] == nums[i - 1] &&
                !visited[i])  // 该数字未用过，但是与上一个数字相同
        ) {
          continue;
        } else {
          visited[i] = true;
          path.push_back(nums[i]);
          backtrack(result, path, nums, visited);
          visited[i] = false;
          path.pop_back();
        }
      }
    }
  }
};
