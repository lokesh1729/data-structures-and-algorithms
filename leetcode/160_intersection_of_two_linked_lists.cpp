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
    ListNode *getIntersectionNode_naive(ListNode *headA, ListNode *headB) {
        while (headA != NULL) {
            ListNode* headTwo = headB;
            while (headTwo != NULL) {
                if (headTwo == headA) {
                    return headA;
                }
                headTwo = headTwo->next;
            }
            headA = headA->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode_with_additional_space(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode* head1 = headA;
        while (head1 != NULL) {
            s.insert(head1);
            head1 = head1->next;
        }
        while (headB != NULL) {
            if (s.find(headB) != s.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0, n2=0;
        ListNode* first=headA;
        ListNode* second=headB;
        while (first != NULL) {
            n1 += 1;
            first = first->next;
        }
        while (second != NULL) {
            n2 += 1;
            second = second->next;
        }
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        if (n1 > n2) {
            int diff = n1 - n2;
            while (diff > 0) {
                ptr1 = ptr1->next;
                diff--;
            }
        } else if (n2 > n1) {
            int diff = n2 - n1;
            while (diff > 0) {
                ptr2 = ptr2->next;
                diff--;
            }
        }
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};
