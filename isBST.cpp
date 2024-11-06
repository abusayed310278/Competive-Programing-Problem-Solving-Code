---------------isBst find--------------------3rd approach---------------------
bool isBST(Node *root,int minn,int maxx)
{
	if(root==NULL)return true;

	return isBST(root->data >minn && root->data <maxx && isBST(root->left,minn,root->data) 
		&& isBST(root->right,root->data,maxx))
}

--------------------------------4th approach-----------------------

int prev=INT_MIN
bool isBST(struct Node* root){
	if(root==NULL)return true;

	if(isBST(root->left)==false)return false;
	if(root->key <=minn)return false;

	prev=root->key;
	return isBST(root->right);
}

--------------------------------fix BST with 2 nodes swapped----

1. do pre order traversal and store that node in arrary 
2.do this loop 

prev=INT_MIN,firt=NIL,second=NIL

for(int i=0;i<n;i++)
{
	if(arr[i] < prev)
	{
		if(first==NIL)first=prev;second=arr[i];
	}
	prev=arr[i];
}

--------------------------------fix BST with 2 nodes swapped----

Node *first,*second,*prev;
void fixBST(Node *root){

	if(root)return;

	fixBST(root->left);

	if(prev!=NULL && root->key < prev->key){
		if(firt==NULL)first=prev;
			second=root;
	}

	prev=root;
	fixBST(root->right);
}

----------------vertical sum----------------------

vector<int> verticalSumRec(Node *root,int hd,vector<int,int>mp,vector<int>& vec)
{
	if(root==NULL)return;

	verticalSumRec(root,hd-1,mp);
	//inorder traversal 
	mp[hd]+=root->data;
	vec.push_back(mp[hd]);

	verticalSumRec(root,hd+1,mp);
}


void verticalSum(Node *root)
{
	map<int,int>mp;
	vector<int>vec;
	verticalSumRec(root,0,mp,vec);

	for(auot x: mp)
		cout<<x.second<<endl;
}