#include "catch.hpp"
#include "leetcode.h"

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) return 0;
    int m = matrix.size(), n = matrix.front().size();
    int result = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0)
          dp[i][j] = matrix[i][j] - '0';
        else if (matrix[i][j] == '1')
          dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;

        result = max(result, dp[i][j]);
      }

    return result * result;
  }
};

SCENARIO("test for leetcode", "[leetcode]") {
  GIVEN("test") { Solution s; }

  WHEN("test 1") {
    THEN("fuck 1") {
      vector<int> result;
      vector<vector<char>> vec{{'1', '0', '1', '0', '0'},
                               {'1', '0', '1', '1', '1'},
                               {'1', '1', '1', '1', '1'},
                               {'1', '0', '0', '1', '0'}};
      /**
       * dp[i][j]表示到达(i, j)位置所能组成的最大正方形的边长
       */
      REQUIRE(Solution().maximalSquare(vec) == 4);
    }
  }
}
