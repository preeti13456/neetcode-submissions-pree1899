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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //think bout the hread as it will change 
        //1,2,3,4,5,6
        //head
        //3->2->1->6->5->4
        //you have to seperate the linked list individually only 
    //remember the nextnode = kthnode->next;
    //store the count of nodes
    int count = 1;
    //edge case no values are there or no linked list 
    if(head==NULL || head->next ==NULL)
    {
        return head;
    }
ListNode* temp = head;
ListNode* prev = NULL;

//count of nodes which we need to reverse if they are <=k and head exists 
while(count<=k && temp)
{
  //        temp
   //         prev
    //1 ->  2->     3-> 4-> 5-> 6
    ListNode* nextNode = temp->next;
    temp->next=prev;
    prev=temp;
    temp=nextNode;
    count++;

    
}
if(count<=k)
{
    //individual linke list creation
    temp=prev;
    prev=NULL;
    while(temp)
    {
        ListNode* nextNode = temp->next;
    temp->next=prev;
    prev=temp;
    temp=nextNode;
    }
}
else
{
    ListNode* oldHead = head;
    head->next=temp;
    head = prev;
    oldHead->next = reverseKGroup(temp,k);

}
return head;
    }
};
