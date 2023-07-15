/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans = new ListNode();
        ListNode *cur = ans;

        while (head)
        {
            while (head->next && head->val == head->next->val) head = head->next;
            cur->next = head;
            cur = head;
            head = head->next;
        }
        return ans->next;
    }
};
// @lc code=end

