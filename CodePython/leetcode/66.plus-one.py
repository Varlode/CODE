#
# @lc app=leetcode id=66 lang=python3
#
# [66] Plus One
#

# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 1
        mem = 1
        while i >= 0 and mem != 0:
            digits[i] += mem
            mem = digits[i] // 10
            digits[i] = digits[i] % 10
            i -= 1
        if mem == 1:
            return ['1'] + digits
        else:
            return digits
# @lc code=end

