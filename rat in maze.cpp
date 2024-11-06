#include<bits/stdc++.h>
using namespace std;

const int N=4;
int mazeMatrix[N][N],sol[N][N];

class Solution{
public:

	void printMatrix()
	{
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<mazeMatrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}


	bool isSafe(int i,int j)
	{
		return (i<N && j<N && mazeMatrix[i][j]==1);
			
	}


	bool solveMazeRecursion(int i,int j)
	{
		if(i==N-1 && j==N-1){
			sol[i][j]=1;
			return true;
		}
		if(isSafe(i,j)){
			if(solveMazeRecursion(i+1,j))return true;
			if(solveMazeRecursion(i,j+1))return true;
			sol[i][j]=0;
		}
		return false;
	}

	bool solveMaze(int i,int j)
	{
		if(solveMazeRecursion(i,j)==false)
			return false;
		else{
			solveMazeRecursion(i,j);
			printMatrix();
			return true;
		}
	}

};




int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	memset(sol,0,sizeof(sol));
	memset(mazeMatrix,0,sizeof(mazeMatrix));
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int x;
			cin>>x;
			mazeMatrix[i][j]=x;
		}
	}

	Solution ob;
	cout<<"path: "<<ob.solveMaze(0,0);

	return 0;
}



