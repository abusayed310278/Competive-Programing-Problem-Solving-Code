#include<bits/stdc++.h>
using namespace std;

const int N=4;
int grid[N][N];

class Solution{

public:

	void show(){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	bool isSafe(int i,int j,int n){
		//for i and columns safe test
		for(int k=0;k<N;k++){
			if(grid[k][j]==n || grid[i][k]==n)return 0;
		}

		//for subgrid safe test
		int s=sqrt(N);
		int rs=i-i%s;
		int cs=j-j%s;

		for(int i=0;i<s;i++){
			for(int j=0;j<s;j++){
				if(grid[i+rs][j+cs]==n)return 0;
			}
		}
		return 1;
	}

	bool solveSodoku()
	{
		int i,j;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(grid[i][j]==0)break;
			}
		}

		if(i==N && j==N)return 1;

		for(int n=1;n<=N;n++){
			if(isSafe(i,j,n)){
				grid[i][j]=n;
				if(solveSodoku())return 1;
			}
		}
		grid[i][j]=0;
		return 0;
	}

	/*void solve()
	{
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int x;
				cin>>x;
				grid[i][j]=x;
			}
		}
	}*/

};

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);


	Solution ob;

	//ob.solve();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int x;
			cin>>x;
			grid[i][j]=x;
		}
	}
	//ob.show();
	cout<<ob.solveSodoku();
	//ob.show();
	return 0;
}


/*

1 0 3 0
0 0 2 1
0 1 0 2
2 4 0 0

*/