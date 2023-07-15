#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
#

# @lc code=start
from re import I


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        while s[i] == ' ' and i >= 0:
            i -= 1
        res = i
        while s[i] != ' ' and i >= 0:
            i -= 1
        res -= i
        return res
# @lc code=end
