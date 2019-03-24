/* Permutation in String
 *
 * [Medium] [AC:37.9% 41K of 108.2K] [filetype:cpp]
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's permutations
 * is the substring of the second string.
 *
 * Example 1:
 *
 * Input:s1 = "ab" s2 = "eidbaooo"
 *
 * Output:True
 *
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 * Example 2:
 *
 * Input:s1= "ab" s2 = "eidboaoo"
 *
 * Output: False
 *
 * Note:
 *
 * The input strings only contain lower case letters.
 *
 * The length of both given strings is in range [1, 10,000].
 *
 * [End of Description] */
#include "leetcode.h"
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<int> m(128);

    for (auto c : s1) {
      ++m[c];
    }

    for (int left = 0, right = 0; right < n2; ++right) {
      if (--m[s2[right] < 0]) {
        while (++m[s2[left]] != 0) {
          left++;
        }
      } else if (right - left + 1 == n1) {
        return true;
      }
    }
    return n1 == 0;
  }
};

// int main(void) {
// string s1 = "ab", s2 = "eidbaooo";
// cout << Solution().checkInclusion(s1, s2) << endl;
// return 0;
// }
