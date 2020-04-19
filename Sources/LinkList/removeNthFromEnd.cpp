//删除倒数第n个结点
/**解析： ① 计算链表长度L（5），第L-n （3）的下一个结点即为将要删除的结点
② 使用两个指针，first second，first结点先走n步，然后在走相同步数，直到first为NULL，此时second结点与first结点相差n个结点，删除second的下一个结点即可

这两种方法都需要定义一个哑头结点，next指向head。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = head;
        int L = 0;
        while (p) {
            p = p->next;
            L++;
        }
        p = dummy;
        for(int i = 0; i < L-n; i++) {
            p = p->next;
        }
        p->next = p->next->next;
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy, *second = dummy;
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};
