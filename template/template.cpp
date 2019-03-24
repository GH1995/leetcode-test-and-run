#include "catch.hpp"
#include "leetcode.h"

// Here is class  solution
class Solution{};


SCENARIO("test for leetcode", "[leetcode]") {
  GIVEN("test") {
    Solution s;
  }

  WHEN("test 1") {
    THEN("fuck 1") {
      vector<int> result;
      REQUIRE(result.empty());
    }
  }
}
