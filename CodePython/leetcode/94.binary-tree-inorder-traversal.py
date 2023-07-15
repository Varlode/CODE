#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def Traverse(cur):
            if cur.left:
                Traverse(cur.left)
            res.append(cur.val)
            if cur.right:
                Traverse(cur.right)
        if root:
            Traverse(root)
        return res
        
# @lc code=end

