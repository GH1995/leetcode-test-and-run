#include "catch.hpp"
#include "leetcode.h"

class Solution {};

SCENARIO("test for leetcode", "[leetcode]") {
  GIVEN("test") {
    Solution s;
    vector<int> example = {1, 2, 3};
  }

  WHEN("test 1") {
    THEN("fuck 1") {
      vector<int> result;
      REQUIRE(result.empty());
    }
  }
}
