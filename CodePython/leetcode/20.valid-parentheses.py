#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 1:
            return False
        meet = []
        op = {}
        op['('] = ')'
        op['['] = ']'
        op['{'] = '}'
        ed = [')', ']', '}']
        for i in range(len(s)):
            if s[i] in ed:
                if len(meet) == 0:
                    return False
                if op[meet.pop()] != s[i]:
                    return False
            else:
                meet.append(s[i])
        if len(meet) > 0:
            return False
        return True
# @lc code=end

