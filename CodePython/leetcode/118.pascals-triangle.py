#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
#

# @lc code=start
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[]]
        if numRows == 1:
            return [1]
        res[0] = [1]
        res[1] = [1, 1]
        mem = [1, 1]
        for i in range(0,numRows):
            
            if len(mem) == numRows:
                return res
# @lc code=end

