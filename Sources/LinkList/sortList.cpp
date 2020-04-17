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
    ListNode *mergeSort(ListNode *l, ListNode *r) {
        ListNode *temp = new ListNode(0);
        ListNode *h = temp;
        while(l && r) {
            if (l->val < r->val) {
                h->next = l;
                l = l->next;
            } else {
                h->next = r;
                r = r->next;
            }
            h = h->next;
        }
        h->next = l == NULL ? r : l; 
        return temp->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *middle = slow->next;
        slow->next = NULL;
        return mergeSort(sortList(head), sortList(middle));
    }
};
