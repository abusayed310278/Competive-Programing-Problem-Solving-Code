#include<bits/stdc++.h>
using namespace std;

const int n=9;
int mat[n][n];

void show(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}


bool isSafe(int mat[][n],int i,int j,int num){
	//for i and columns safe test
	for(int k=0;k<n;k++){
		if(mat[k][j]==num || mat[i][k]==num)return false;
	}

	//for subgrid safe test
	int sx=(i/3)*3;
	int sy=(j/3)*3;
	

	for(int x=sx;x<sx+3;x++){
		for(int y=sy;y<sy+3;y++){
			if(mat[x][y]==num)return false;
		}
	}
	return true;
}


bool solveSudoku(int mat[][n],int i,int j){

	//base case
	if(i==n){
		show();
		return 1;
	}

	//rec case
	if(j==n){
		return solveSudoku(mat,i+1,0);
	}

	//skip the prefilled cell
	if(mat[i][j]!=0){
		return solveSudoku(mat,i,j+1);
	}

	for(int num=1;num<=n;num){
		if(isSafe(mat,i,j,num)){
			mat[i][j]=num;
			bool subprob=solveSudoku(mat,i,j+1);
			if(subprob==true){
				return true;
			}
		}
	}
	mat[i][j]=0;
	return false;


}

int main()
{
	//int n;cin>>n;
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;cin>>x;
			mat[i][j]=x;
		}
	}

	if(!solveSudoku(mat,0,0)){
		cout<<"No Solution Exists.";
	}	

	return 0;
	
}

/*

5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9


3 0 6 5 0 8 4 0 0 
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0 
9 0 0 8 6 3 0 0 5 
0 5 0 0 9 0 6 0 0 
1 3 0 0 0 0 2 5 0 
0 0 0 0 0 0 0 7 4 
0 0 5 2 0 6 3 0 0 

*/