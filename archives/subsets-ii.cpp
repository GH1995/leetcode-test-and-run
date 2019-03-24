/* Subsets II
 *
 * [Medium] [AC:41.6% 191.1K of 459.4K] [filetype:cpp]
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: [1,2,2]
 *
 * Output:
 *
 * [
 *
 *   [2],
 *
 *   [1],
 *
 *   [1,2,2],
 *
 *   [2,2],
 *
 *   [1,2],
 *
 *   []
 *
 * ]
 *
 * [End of Description] */
// #include "leetcode.h"
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> path;
    sort(nums.begin(), nums.end());

    backtrack(result, path, nums, 0);

    return result;
  }

  void backtrack(vector<vector<int>> &result, vector<int> &path,
                 vector<int> &nums, int start) {
    result.push_back(path);

    for (int i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1]) continue;  // skip duplicates
      path.push_back(nums[i]);
      backtrack(result, path, nums, i + 1);
      path.pop_back();
    }
  }
};

// int main(void) {
  // vector<int> v = {1, 2, 2};
  // auto s = Solution().subsetsWithDup(v);
  // print_2_vector(s);
  // return 0;
// }
