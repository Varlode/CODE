#
# @lc app=leetcode id=67 lang=python3
#
# [67] Add Binary
#

# @lc code=start
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) > len(b):
            ab = len(a) - len(b)
            for i in range(ab):
                b = '0' + b
        else:
            ab = len(b) - len(a)
            for i in range(ab):
                a = '0' + a
        i = len(a) - 1
        mem = 0
        res = ''
        while i >= 0:
            sum = int(a[i]) + int(b[i])
            res = str((sum + mem) % 2) + res
            mem = (sum + mem) // 2
            i -= 1
        if mem == 1:
            return '1' + res
        return res
# @lc code=end

