#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *root = NULL;

TreeNode *Insert(TreeNode *root, int key)
{

    if (!root)
        return new TreeNode(key);

    if (key > root->val)
        root->right = Insert(root->right, key);
    else if (key < root->val)
        root->left = Insert(root->left, key);

    return root;
}

TreeNode *search(TreeNode *root, int key)
{

    if (!root or root->val == key)
        return root;

    if (key > root->val)
        return search(root->right, key);

    return search(root->left, key);
}

TreeNode* inpre(TreeNode* root){
    while(root and root->right!=NULL)root=root->right;

    return root;
}

int height(TreeNode* root){
    if(!root)return -1;

    return max(height(root->left),height(root->right));
}


TreeNode* insucc(TreeNode* root){

    while(root and root->left!=NULL)root=root->left;

    return root;
}

void Inorder(TreeNode* root)
{
    if (root != NULL) {
        Inorder(root->left);
        cout<<root->val<<" ";
        Inorder(root->right);
    }
}

TreeNode* Delete(TreeNode* p,int key)
{
	
	if(p==NULL)return NULL;
	if (root->left == NULL) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
    }

	
	if(key < p->val)
		p->left=Delete(p->left,key);
	else if(key >p->val)
		p->right=Delete(p->right,key);
	else{
		
		if(height(p->left)>height(p->right)){
			TreeNode* q=inpre(p->left);
			p->val=q->val;
			p->left=Delete(p->left,q->val);
				
		}else{
			TreeNode* q=insucc(p->right);
			p->val=q->val;
			p->right=Delete(p->right,q->val);
				
			
			
		}
	}
	
	return p;
}

void BFS(TreeNode* root){

    if(!root)return;

    queue<TreeNode*>q;
    q.push(root);

    vector<int>ans;
    while(!q.empty()){

         

         int sz=q.size();
         for(int i=0;i<sz;i++){

            auto cur=q.front();q.pop();    
            ans.push_back(cur->val);
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);

         }   


    }

    for(auto x:ans)cout<<x<<" ";

    return;
}

void solve()
{

    // TreeNode *root = NULL;
        
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 80);

    // int key = 10;
    // if (search(root, key) == NULL)
    //     cout << key << "Not Found" << endl;
    // else
    //     cout << key << " " << "found" << endl;

    // Inorder(root);
    // BFS(root);

    
    root=Delete(root,20);
    Inorder(root);


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}