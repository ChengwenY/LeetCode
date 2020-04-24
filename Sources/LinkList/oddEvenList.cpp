/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//分析 ： 拉链法求解，注意最后一个奇数节点的next指针是偶数节点的头指针，所以需要额外定义oddNode evenNode临时变量
//时间复杂度： O(n) 空间复杂度O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *oddHead = head, *oddNode = oddHead;
        ListNode *evenHead = head->next, *evenNode = evenHead;
        while(oddNode != NULL && evenNode != NULL && oddNode->next!= NULL && evenNode->next != NULL) {
            oddNode->next = oddNode->next->next;
            evenNode->next = evenNode->next->next;
            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }

        oddNode->next = evenHead;
        return oddHead;
    }
};
