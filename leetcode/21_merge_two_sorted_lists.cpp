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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* res = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                res->next = l1;
                l1 = l1->next;
            } else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        while (l1) {
            res->next = l1;
            l1 = l1->next;
            res = res->next;
        }
        while (l2) {
            res->next = l2;
            l2 = l2->next;
            res = res->next;
        }
        // optimization. Just splice the remaining linked list and link
        // it to the current head
        //if (l1 != NULL) {
            //res->next = l1;
        //} else if (l2 != NULL) {
            //res->next = l2;
        //}
        return head->next;
    }
};
