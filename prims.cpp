#include<bits/stdc++.h>
using namespace std;

const int n=7;

int near[n+1];
int g[n+1][n+1];
int t[2][n+1];

void primsAlgo()
{	
	int minn=INT_MAX;
	int u,v;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]<minn){
				minn=g[i][j];
				u=i;v=j;
			}
		}
	}
	t[0][0]=u;t[1][0]=v;
	near[u]=near[v]=0;
	for(int i=1;i<=n;i++){
		if(near[i]!=0 && a[i][u] < a[i][v])
			near[i]=u;
		else
			near[i]=v;
	}
	int k;
	for(int i=1;i<n-1;i++){
		for(int j=0;j<n;j++){
			if(near[j]!=0 && g[j][near[j]] <minn)
			{
				k=j;
				minn=g[j][near[j]];
			}
		}
		t[0][j]=k;
		t[1][i]=near[k];
		near[k]=0;

		for(int j=0;j<n;j++){
			if(near[j]!=0 && g[j][k] < g[j][near[j]])
				near[j]=k;
		}

	}

}

int main()
{
	memset(near,INT_MAX,sizeof(near));
	int g[n][n]={
            {I,25,I,I,I,15,I},
            {25,I,12,I,I,I,I},
            {I,12,I,8,I,I,10},
            {I,12,I,8,I,I,I},
            {I,I,I,16,I,20,14},
            {5,I,I,I,20,I,I},
            {I,10,I,14,18,I,I}


    }

	return 0;
}