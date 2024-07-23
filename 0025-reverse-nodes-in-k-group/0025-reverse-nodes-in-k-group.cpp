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
    ListNode * findkth(ListNode * p  ,int k)
    {
        ListNode * temp = p ;
        k-=1 ;
        while(temp!=NULL && k>0)
        {k--;
            temp = temp->next ;
        }
        return temp ;
    }
    void reverselist(ListNode * p)
    {
        if(p==NULL || p->next==NULL)
        {
            return ;
        }
        ListNode * prev =NULL , *curr= p ;
        while(curr!=NULL)
        {
            ListNode * nxt =curr->next ;
            curr->next  =prev ;
            prev = curr ;
            curr= nxt ;
        }
    }
    ListNode * revesek(ListNode * head ,int k)
    {
        if(head==NULL || head->next==NULL)
        {
            return head ;
        }
        ListNode * temp= head ;
        ListNode * prevLast = NULL ;
        while(temp!=NULL)
        {
            ListNode * kthele= findkth(temp, k) ;
            if(kthele==NULL)
            {
                if(prevLast)prevLast->next =temp ;
                break ;
            }
            ListNode * lastNode = kthele->next ;
            kthele->next =NULL ;
            reverselist(temp) ;
            if(temp==head)
            {
                head=  kthele ;
            }
            else
            {
                prevLast->next= kthele ;
            }
            prevLast = temp ;
            temp = lastNode ;
        }
        return head ;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return revesek(head , k );
    }
};