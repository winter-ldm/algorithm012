/**
 * 没有额外申请空间，空间复杂度为O(1)
 * 只需要循环遍历最短链表即可，时间复杂度为O(n)
 * 需要第三方指针指向两个链表中的最小一位，当遍历完最短链表，第三方指针指向当前长链表即可
 **/

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
        ListNode tNode(0), *l3 = &tNode;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                l3->next = l1;
                l1 = l1->next;
            }
            else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        l3->next = l1 ? l1 : l2;
        
        return tNode.next;
    }
};