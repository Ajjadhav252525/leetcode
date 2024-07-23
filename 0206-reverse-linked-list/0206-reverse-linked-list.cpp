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
    ListNode * ans;
    void ok(ListNode * parent ,ListNode * child)
    {
        if(child==NULL)
        {
            ans =parent ;
            return  ;
        }
        ok(child  ,child->next) ;
        child->next = parent ;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
       if(head==NULL || head->next==NULL)
       {
           return head ;
       }
        ok(NULL , head) ;
        return ans ;
    }
};