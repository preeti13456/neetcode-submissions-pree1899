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
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int rem = 0;
        ListNode* ans = new ListNode(), *cur = ans;

        while(cur1||cur2)
        {
            int val1 = (cur1)?cur1->val:0;
            int val2 = (cur2)?cur2->val:0;
            int sum = val1+val2+rem;
            if(sum>=10)
            {
                sum-=10;
                rem = 1;
            }
            else
            rem=0;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if(cur1) cur1 = cur1->next;
            if(cur2) cur2 = cur2->next;
        }
        if(rem==1) cur->next = new ListNode(1);
        return ans->next;
    }
};
