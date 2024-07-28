/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 void preorder(TreeNode * p , vector<int>&ok)
 {
    if(p==NULL)
    {
        return ;
    }
    else
    {
        ok.push_back(p->val) ;
        preorder(p->left , ok) ;
        preorder(p->right ,ok) ;
    }
 }
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ok ;
        // preorder(root , ok) ;
        // return ok ;
        //-----------------
        //morris baby
        TreeNode * cur  =root ;
        while(cur)
        {
            if(cur->left==NULL)
            {
                ok.push_back(cur->val) ;
                cur =cur->right ;
            }
            else
            {
                TreeNode * prev = cur->left ;
                while(prev->right && prev->right!=cur)
                {
                    prev  =prev->right ;
                }
                if(prev->right==NULL)
                {
                    prev->right = cur ;
                    ok.push_back(cur->val);
                    cur =cur->left ;
                }
                else
                {
                    prev->right =NULL ;
                    cur=cur->right ;
                }
            }
        }
        return ok ;
    }
};