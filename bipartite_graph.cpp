#include<bits/stdc++.h>
using namespace std;

const int N=5;

int g[N][N];
static int x[N];
int mColor,node,edge;

void input()
{
	cin>>node>>mColor>>edge;

	for(int i=1;i<=edge;i++){
		
			int x,y;cin>>x>>y;
			g[x][y]=1;
			g[y][x]=1;
	}

}

void showOutput(){
	for(int i=1;i<=node;i++)
		cout<<x[i]<<" ";
}

bool isPlace(int k,int color){
	for(int col=1;col<=k;col++){
		if(g[k][col] && x[col]==color)
			return false;

	}
	return true;
}

void graphColoring(int k){
	for(int color=1;color<=mColor;color++){
		if(isPlace(k,color))
		{	
			x[k]=color;			
			graphColoring(k+1);	
		}	
	}

}



int main()
{
	#ifndef st
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	input();
	graphColoring(1);
	showOutput();	
		
	return 0;
}