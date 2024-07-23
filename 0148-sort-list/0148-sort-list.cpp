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
    ListNode* sortList(ListNode* head) {
       multiset<int>st ;
       ListNode * p = head ;
       while(p!=NULL)
       {
        st.insert(p->val) ;
        p=p->next ;
       }
       p=head ;
       for(auto it:st)
       {
            p->val = it ;
            p=p->next ;
       }
        return head ;
    }
};