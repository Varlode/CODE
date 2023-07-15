#
# @lc app=leetcode id=13 lang=python3
#
# [13] Roman to Integer
#

# @lc code=start
class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {}
        res = 0
        roman['I'] = 1
        roman['V'] = 5
        roman['X'] = 10
        roman['L'] = 50
        roman['C'] = 100
        roman['D'] = 500
        roman['M'] = 1000
        for i in range(len(s)):
            if (roman[s[i]] > roman[s[i - 1]]) & (i >= 1):
                res += roman[s[i]] - 2 * roman[s[i - 1]]
            else:
                res += roman[s[i]]
        return res
# @lc code=end

