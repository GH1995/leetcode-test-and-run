/* Subsets
 *
 * [Medium] [AC:51.3% 336.5K of 656.1K] [filetype:cpp]
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: nums = [1,2,3]
 *
 * Output:
 *
 * [
 *
 *   [3],
 *
 *   [1],
 *
 *   [2],
 *
 *   [1,2,3],
 *
 *   [1,3],
 *
 *   [2,3],
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
  vector<vector<int>> subsets(vector<int> &nums) {
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
      path.push_back(nums[i]);
      backtrack(result, path, nums, i + 1);
      path.pop_back();
    }
  }
};

// int main(void) {
  // vector<int> v = {1, 2, 3};
  // auto s = Solution().subsets(v);
  // print_2_vector(s);
  // return 0;
// }
