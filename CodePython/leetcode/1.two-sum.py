#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        meet = {}
        
        for i in range(1, len(nums)):
            meet[nums[i - 1]] = i - 1
            
            if target - nums[i] in meet:
                return [meet[target - nums[i]], i]  
# @lc code=end
