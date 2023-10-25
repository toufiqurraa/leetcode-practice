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
    ListNode* reverseList(ListNode* head) {
        auto curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            auto nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while(fast) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        auto mid_head = reverseList(slow);
        int maxSum = 0;
       
        while(mid_head) {
            maxSum = max(maxSum, head -> val + mid_head -> val);
            head = head -> next;
            mid_head = mid_head -> next;
        }

        return maxSum;
    }
};