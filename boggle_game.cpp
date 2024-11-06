#include<bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

class Node{
public:
	char s;
	unordered_map<char,Node*>children;
	string word;
	bool isTerminal;

	Node(char s){
		this->s=s;
		isTerminal=false;
		word="";
	}
};

class Trie{
public:
	Node *root;

	Trie(){
		root=new Node('\0');
	}

	void addword(string word){
		Node *temp=root;

		for(auto ch:word){
			if(temp->children.count(ch)==0){
				temp->children[ch]=new Node(ch);
			}
			temp=temp->children[ch];
		}
		//last Node
		temp->isTerminal=true;
		temp->word=word;
	}
};

void dfs(char board[][N],Node *node,int i,int j,bool visited[][N],unordered_set<string>& output){
	//base case
	char ch=board[i][j];
	if(node->children.count(ch)==0){
		return;
	}

	//otherwise trie contains this node 
	visited[i][j]=true;
	node=node->children[ch];

	//if it is a terminal node in the trie
	if(node->isTerminal){
		output.insert(node->word);
	}

	//explore the neighbours
			// 1  2 3 4 5  6  7  8 
	int dx[]={ 0, 1,1,1,0,-1,-1,-1};
	int dy[]={-1,-1,0,1,1, 1, 0,-1};

	for(int k=0;k<8;k++){
		int ni=i+dx[k];
		int nj=j+dy[k];

		if(ni>=0 and nj>=0 and ni<M and nj<N and !visited[ni][nj]){
			dfs(board,node,ni,nj,visited,output);
		}
	}

	//if it is in bounds and is not visited


	//last step(backtracking)
	visited[i][j]=false;
	return;


}

int main()
{
	freopen("inputf.in","r",stdin);
	
	freopen("outputf.in","w",stdout);

	string words[]={"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};
	char board[M][N]={
		{'S','E','R','T'},
		{'U','N','K','S'},
		{'T','C','A','T'}
	};

	//1.Trie

	Trie t;
	for(auto w:words){
		t.addword(w);
	}
	//2.take a container to store words that are found in dfs search
	unordered_set<string>output;


	//3.step 8-way dfs search from every cell
	bool visited[M][N]={0};

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			dfs(board,t.root,i,j,visited,output);
		}
	}

	//4.print the output

	for(auto w:output){
		cout<<w<<endl;
	}

	return 0;
}