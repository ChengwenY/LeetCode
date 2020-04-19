/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 合并k个有序链表 思路：归并算法依次两两合并，
//时间复杂度O(nlogk) n是所有链表节点数 k是数组内链表个数  每次都几乎遍历了所有的结点 遍历了logK次
//空间复杂度O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return merge(lists, 0, lists.size()-1);
    }

    ListNode *merge(vector<ListNode *>& lists, int left, int right) {
        if (left >= right) return lists[right];
        int middle = left + (right-left)/2;
        ListNode *l = merge(lists, left, middle);
        ListNode *r = merge(lists, middle+1, right);
        return mergeTwoList(l, r);
    }

    ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = l1 == NULL ? l2 : l1;
        return dummy->next;
    }
};
