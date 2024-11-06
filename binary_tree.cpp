#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node *left,*right;

	Node(int d){
		val=d;
		left=NULL;
		right=NULL;
	}
};

void preorder(Node *root)
{
    if(root)
    {
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

Node* NodeBuild(){


	int d;cin>>d;

	if(d==-1)return NULL;

	Node *n=new Node(d);
	n->left= NodeBuild();
	n->right= NodeBuild();

	return n;
}

int height(Node *root){
	if(root==NULL)return 0;

	int h1,h2;
	//post order traversal 
	h1=height(root->left);
	h2=height(root->right);
	return 1+max(h1,h2);
}

void leveOrderPrint(Node *root){

	queue<Node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		Node *temp=q.front();
		//q.pop();

		if(temp==NULL)
		{
			q.pop();
			cout<<endl;
			if(!q.empty()){q.push(NULL);}

		}else{
			q.pop();
			cout<< temp->val<<" ";
			if(temp->left){q.push(temp->left);}
			if(temp->right){q.push(temp->right);}
		}

	}
	return;
}

//Tc=O(n*n)
int diameter(Node *root)
{
	if(root==NULL)return 0;
	int d1,d2,d3;
	d1=height(root->left)+height(root->right);
	d2=diameter(root->left);
	d3=diameter(root->right);

	return max(d1,max(d2,d3));
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	Node *root= NodeBuild();
	//leveOrderPrint(root);

	//preorder(root);

	//cout<<endl;
	//cout<<diameter(root)<<endl;
	
	return 0;
}

/*

1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

*/