#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#

# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        y = 1
        while y*y <= x:
            y += 1
        return y - 1
        
# @lc code=end

