/*
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (47.55%)
 * Total Accepted:    64.4K
 * Total Submissions: 135.4K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverse(l1);
        ListNode* rl2 = reverse(l2);
        ListNode* res = NULL;
        int c = 0;
        while (rl1 != NULL || rl2 != NULL) {
            int val1 = rl1 == NULL ? 0 : rl1->val;
            int val2 = rl2 == NULL ? 0 : rl2->val;
            int d = c + val1 + val2;
            res = insert0(res, d % 10);
            c = d / 10;
            if (rl1 != NULL) {
                rl1 = rl1->next;
            }
            if (rl2 != NULL) {
                rl2 = rl2->next;
            }
        }
        if (c != 0) {
            res = insert0(res, c);
        }
        return res;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* p = head;
        while (p != NULL) {
            ListNode* q = p->next;
            p->next = prev;
            prev = p;
            p = q;
        }
        return prev;
    }

    ListNode* insert0(ListNode* head, int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        return node;
    }
};

