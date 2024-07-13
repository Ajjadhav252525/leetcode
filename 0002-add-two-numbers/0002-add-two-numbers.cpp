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
    ListNode* addTwoNumbers(ListNode* p, ListNode* q) {
        ListNode * res = new ListNode (2) ;
        ListNode *head = res ;
        int carry=0 ;
        while(p!=NULL && q!=NULL)
        {
            int sum = p->val+q->val+carry ;
            if(sum <=9)
            {
                res->next = new ListNode(sum) ;
                carry = 0 ;
                res = res->next ;
            }
            else
            {
                res->next = new ListNode(sum%10) ;
                carry =1 ;
                res = res->next ;
            }
            p=p->next ;
            q =q->next ;
        }
        while(p!=NULL)
        {
            int sum = carry + p->val ;
            if(sum >9)
            {
                res->next = new ListNode(sum%10) ;
                carry =1 ;
                res= res->next ;
            }
            else
            {
                res->next =new ListNode(sum);
                res=  res->next ;
                carry = 0 ;
            }
            p=p->next ;
        }
        while(q!=NULL)
        {
            int sum = carry + q->val ;
            if(sum >9)
            {
                res->next = new ListNode(sum%10) ;
                carry =1 ;
                res= res->next ;
            }
            else
            {
                res->next =new ListNode(sum);
                res=  res->next ;
                carry = 0 ;
            }
            q=q->next ;
        }
        if(carry==1)
        {
            res->next= new ListNode(1);
        }
        return head->next ;
    }
};