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
 void done(TreeNode * p , int level, vector<int>&ok)
 {
    if(p==NULL)
    {
        return ;
    }
    if(ok.size()==level)
    {
        ok.push_back(p->val) ;
    }
    done(p->right , level+1 , ok);
    done(p->left , level+1 , ok);

 }
class Solution {
public:
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int>res ;
    //     if(root ==NULL)
    //     {
    //         return {} ;
    //     }
    //     queue<TreeNode *>q ;
    //     q.push(root) ;
    //     // res.push_back(root->val) ;
    //     while(!q.empty())
    //     {
    //         int x ;
    //          int s = q.size() ;
    //         // vector<int>ok ;
    //         for(int i=0 ;i<s ;i++)
    //         {
    //             TreeNode * p = q.front();
    //             q.pop() ;
    //             if(p->left!=NULL)q.push(p->left) ;
    //             if(p->right!=NULL)q.push(p->right) ;
    //             x = p->val ;
    //         }
    //         res.push_back(x) ;
    //     }
    //     return res ;
    // }
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int>ok ;
        done(root ,0,  ok) ;
        return ok ;
    }
};