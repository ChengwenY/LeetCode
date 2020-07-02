struct ListNode {
    ListNode *next;
    int val;
    ListNode(int x) : val(x), next(NULL) {};
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=NULL, *temp = head;
        while (head) {
            temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};
