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
public:

    vector<int> rightSideView(TreeNode* root) 
    {
        
        vector<int>res;
        queue<TreeNode*>q;

        if(root==NULL)return res;
        
        
        q.push(root->val);

        while(!q.empty())
        {

            for(int i=0;i<q.size();i++)
            {

                TreeNode *current=q.front();
                q.pop();

                if(i==q.size()-1)res.push_back(root->val);

                if(current->left!=NULL)q.push_back(current->left);
                if(current->right!=NULL)q.push_back(current->right);
            }
        }


       return res;
    }
    
     
};