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
    ListNode* reverseList(ListNode* head) {
        //0->1->2->3

        if(head==nullptr)
        {
            return nullptr;
        }
        if(head->next == nullptr)
        {
            return head;
        }
        //   reverse reverse reverse
        //0->1->    2->     3
        //0->
        ListNode* new_head = reverseList(head->next);
        //head = 2, head->next = 3
        //2->next = null
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};
