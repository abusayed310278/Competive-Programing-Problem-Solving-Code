class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        if(root==NULL)return true;
        return dfs(root,0,0);
        
    }

    bool dfs(TreeNode *root,int min,int max)
    {
        if(root==NULL)return true;

        if((min!=NULL && root->val <= min) || (max!=NULL) && root->val >=max)
            return false;

        return dfs(root->val,min,root->val) && dfs(root->val,root->val,max);
    }
};