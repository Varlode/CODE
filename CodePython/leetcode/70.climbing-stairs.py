#
# @lc app=leetcode id=70 lang=python3
#
# [70] Climbing Stairs
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        f1 = 1
        f2 = 2
        fn = 0
        for i in range(3, n + 1):
            fn = f1 + f2
            f1 = f2
            f2 = fn
        return fn
# @lc code=end

