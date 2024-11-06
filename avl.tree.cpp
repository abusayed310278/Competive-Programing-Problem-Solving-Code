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

    int val, height;
    TreeNode *left, *right;
    TreeNode() : val(0), height(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), height(1), left(left), right(right) {}
};

TreeNode *inpre(TreeNode *root)
{
    while (root and root->right != NULL)
        root = root->right;

    return root;
}

int height(TreeNode *root)
{
    if (!root)
        return -1;

    return max(height(root->left), height(root->right));
}

TreeNode *insucc(TreeNode *root)
{

    while (root and root->left != NULL)
        root = root->left;

    return root;
}

int getBalance(TreeNode *root)
{

    if (!root)
        return 0;

    return height(root->left) - height(root->right);
}

TreeNode *leftrotate(TreeNode *x)
{

    TreeNode *y = x->right;
    TreeNode *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

TreeNode *rightrotate(TreeNode *y)
{

    TreeNode *x = y->left;
    TreeNode *t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return x;
}

TreeNode *Insert(TreeNode *root, int key)
{

    if (!root)
        return new TreeNode(key);

    if (key < root->val)
        root->left = Insert(root->left, key);
    else if (key > root->val)
        root->right = Insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance < -1 and key > root->right->val)
        return leftrotate(root);
    else if (balance > 1 and key < root->left->val)
        return rightrotate(root);
    else if (balance < -1 and key < root->right->val)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    else if (balance > 1 and key > root->left->val)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    return root;
}

void BFS(TreeNode *root)
{

    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    vector<int> ans;
    while (!q.empty())
    {

        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {

            auto cur = q.front();
            q.pop();
            ans.push_back(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }

    for (auto x : ans)
        cout << x << " ";

    return;
}

void solve()
{

    TreeNode *root = NULL;

    root = Insert(root, 9);
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 0);
    root = Insert(root, 6);
    root = Insert(root, 11);
    root = Insert(root, -1);
    root = Insert(root, 1);
    root = Insert(root, 2);

    BFS(root);
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