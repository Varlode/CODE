#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
#

# @lc code=start
class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        res = ''
        if len(strs) == 1:
            return strs[0]
        for i in range(len(strs[0])):
            for j in range(len(strs)):
                if i >= len(strs[j]):
                    return res
                if strs[0][i] != strs[j][i]:
                    return res
            res += strs[0][i]
        return res
# @lc code=end

