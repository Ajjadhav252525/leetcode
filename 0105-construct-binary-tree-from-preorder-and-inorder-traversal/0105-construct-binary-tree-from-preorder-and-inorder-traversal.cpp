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
class Solution {
    void createmapping(vector<int> &in , int n , unordered_map<int ,int>&mp )
    {
        for(int i=0 ;i<n ;i++)
        {
            mp[in[i]] =i;
        }
    }
    TreeNode * construct(vector<int> &p, vector<int> &i , int &index, int n , int start , int end ,unordered_map<int ,int>&mp )
    {
        if(index >=n || start > end)
        {
            return NULL ;
        }
        TreeNode * root= new TreeNode(p[index++]);
        int pos = mp[root->val] ;
        root->left = construct(p ,i , index, n, start, pos-1 , mp);
        root->right= construct(p, i , index, n , pos+1  ,end , mp) ;
        return root ;
    }
public:
    TreeNode *buildTree(vector<int> &p, vector<int> &i) 
    {
        unordered_map<int ,int>mp ;
        createmapping( i , p.size() , mp);
        int preindex=0 ;
        TreeNode * root =construct(p , i ,preindex , p.size() ,0 , p.size()-1 , mp);
        return root ;
    }
};