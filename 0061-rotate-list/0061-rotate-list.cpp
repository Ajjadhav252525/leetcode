class Solution {
    int cnt(ListNode * p)
    {
        int res=0 ;
        while(p)
        {
            res++ ;
            p=p->next ;
        }
        return res ;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int ok= cnt(head) ;
        if(ok<=1)
        {
            return head ;
        }
        ok =k%ok ;
        // cout<<ok ;
        ListNode * p=head;
                ListNode * z =p ;
        while(ok>=0)
        {
            ok-- ;z=p;
            p = p->next ;
        }
        ListNode* q = head ;
        while(p!=NULL)
        {
            z=p ;
            p=p->next ;
            q=q->next;
        }
        z->next= head ;
        p =q->next ;
        q->next =NULL ;
        return p;
    }
};