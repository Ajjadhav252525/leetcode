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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head ;
        }
        ListNode * temp ;
        int cnt=0 ;
        ListNode * evenhead = new ListNode (-1) , *eventail =evenhead ;
        ListNode * oddhead = new ListNode (-1) , *oddtail =oddhead ;
        while(head)
        {
            temp =head ;
            head =head->next ;
            temp->next =NULL ;
            if(cnt&1)
            {
                oddtail->next = temp ;
                oddtail =temp ;
            }
            else
            {
                eventail->next =temp ;
                eventail = temp ;
            }
            cnt++ ;
        }
        eventail->next =oddhead->next ;
        return evenhead->next ;
    }
};