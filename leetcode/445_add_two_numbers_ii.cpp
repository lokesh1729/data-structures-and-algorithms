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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode* head = l1;
        while (head != NULL) {
            s1.push(head->val);
            head = head -> next;
        }
        head = l2;
        while (head != NULL) {
            s2.push(head->val);
            head = head->next;
        }
        ListNode* dummy = NULL;
        int carry = 0;
        while(!s1.empty() || !s2.empty()) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            ListNode* newNode = new ListNode(sum % 10, NULL);
            newNode->next = dummy;
            dummy = newNode;
            carry = sum / 10;
        }
        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);
            newNode->next = dummy;
            return newNode;
        }
        return dummy;
    }
};
