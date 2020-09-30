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
    // Time: O(n)
    // Space: O(1)
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        auto oh = head, ot = oh;
        auto eh = head->next, et = eh;
        auto p = head->next->next;
        while (p) {
            ot = ot ->next = p;
            p = p->next;
            if (p) {
                et = et->next = p;
                p = p->next;
            }
        }
        ot->next = eh;
        et->next = nullptr;
        return oh;
    }
};
