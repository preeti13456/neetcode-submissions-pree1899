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
    void reorderList(ListNode* head) {
        vector<ListNode*>node;
        int n = 0;
        ListNode* curr = head;
        while(curr)
        {
            n++;
            node.push_back(curr);
            curr = curr->next;
        }
        curr = head;
        int step = n/2;
        for(int i=0; i<step; i++)
        {
            ListNode* tmp = curr->next;
            curr->next = node[n-1-i];
            curr->next->next = node[i+1];
            curr = tmp;
        }
        curr->next = nullptr;
        return;
    }
};
