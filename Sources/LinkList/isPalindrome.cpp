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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow, *temp = NULL, *pre = NULL;

        while (curr) {
            temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        while(pre && head) {
            if (pre->val != head->val) return false;
            pre = pre->next;
            head = head->next;
        }
        return true;


    }
};
