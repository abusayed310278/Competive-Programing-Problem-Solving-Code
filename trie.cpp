#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
	TrieNode *child[26];
	bool isEnd;
	TrieNode()
	{
		isEnd=false;
		for(int i=0;i<26;i++)
			child[i]=NULL;
	}	

};


TrieNode *root=NULL;

bool Search(string key) 
{
	TrieNode *curr=root;
	for(int i=0;i<key.length();i++)
	{	
		int index=key[i]-'a';
		if(curr->child[index]==NULL)
			return false;
		curr=curr->child[index];

	}
	return curr->isEnd;

}

bool isEmpty(TrieNode *root){
	for(int i=0;i<26;i++){
		if(root->child[i]!=NULL)return false;
	}
	return true;
}

TrieNode *delkey(TrieNode *root,string &key,int i){

	if(root=NULL)return NULL;

	if(i==key.length()){
		root->isEnd=false;

		if(isEmpty(root)==true){
			delete(root); root=NULL; //return root;
		}
		return root;
	}

	int index=key[i]-'a';

	root->child[index]=delkey(root->child[index],key,i+1);

	if(isEmpty(root) && root->isEnd==false){
		delete(root); root=NULL; //return root;
	}

	return root;
}

void insert(string key)
{
	TrieNode *curr=root;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(curr->child[index]==NULL)
			curr->child[index]=new TrieNode();
		curr=curr->child[index];

	}		
	curr->isEnd=true;
	
}	

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	string keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" };
	
	int n=sizeof(keys)/sizeof(keys[0]);
	insert("the");
	Search("the")?cout<<"yes"<<endl :cout<<"no"<<endl;

	delkey(root,"the",0);
	
	return 0;	
}