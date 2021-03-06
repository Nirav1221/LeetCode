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
    // Time: O(mnlogm)
    // Space: O(m)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* & a, ListNode* & b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto node : lists) {
            if (node)
                pq.push(node);
        }
        ListNode * dummy = new ListNode(-1), * cur = dummy;
        while (pq.size()) {
            auto node = pq.top();
            pq.pop();
            cur->next = node;
            cur = node;
            if (node->next)
                pq.push(node->next);
        }
        return dummy->next;
    }
};
