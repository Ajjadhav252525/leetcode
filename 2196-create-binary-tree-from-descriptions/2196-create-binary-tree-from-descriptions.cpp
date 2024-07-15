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
    unordered_map<int , pair<int ,int>>data ;
    void construct(TreeNode * p)
    {
        if(data.find(p->val)!=data.end())
        {
            if(data[p->val].first!=0){p->left =new TreeNode(data[p->val].first);
            construct(p->left);}
             if(data[p->val].second!=0){p->right =new TreeNode(data[p->val].second);
            construct(p->right);}
        }
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        vector<int>one ,two ;
        for(auto it:d)
        {
            int a =it[0] ;
            int b =it[1];
            int c = it[2] ;
            one.push_back(a);
            two.push_back(b);
            if(c==0)
            {
                data[a].second =b ;
            }
            else
            {
                data[a].first = b ;
            }
        }
        int rootval =one[0];
        for(auto it:one)
        {
            if(find(two.begin() , two.end() , it)==two.end())
            {
                rootval = it ;
                break ;
            }
        }
        TreeNode * root =new TreeNode(rootval) ;
        construct(root) ;
        return root ;
    }
};