#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int dp[N];
int DP[N];

//Recursive approach: Tc=O(k^n)
int countWays(int n,int k)
{
	if(n==0)return 1;
	if(n<0)return 0;

	int ans=0;

	for(int jump=1;jump<=k;jump++){
		ans+=countWays(n-jump,k);
	}
	return ans;
}

//Top down apporach: Tc=O(n*k)

int countWaysTopDown(int n,int k)
{
	if(n==0)return 1;
	if(n<0)return 0;

	if(dp[n]!=-1)return dp[n];

	int ans=0;

	for(int jump=1;jump<=k;jump++){
		ans+=countWays(n-jump,k);
	}
	return dp[n]=ans;
}

//Bottom up approach: Tc=O(n*k), Sc=O(n)
int countWaysBottomUp(int n,int k)
{
	vector<int>DP(n+1,0);
	DP[0]=1;

	for(int i=1;i<=n;i++){ //<---O(n)
		for(int jump=1;jump<=k;jump++){ //<--O(k)
			if(i-jump >=0)
				DP[i]+=DP[i-jump];
		}
	}
	return DP[n];
}

int countWaysOpt(int n,int k)
{
	vector<int>opt(n+1,0);

	opt[0]=1;
	opt[1]=1;

	for(int i=2;i<=k;i++)
	{
		opt[i]=2*opt[i-1];
	}

	for(int i=k+1;i<=n;i++){
		opt[i]=2*opt[i-1]-opt[i-k-1];
	}

	return opt[n];
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	memset(dp,-1,sizeof(dp));

	int n,k;cin>>n>>k;
	
	cout<<countWays(n,k)<<endl;
	cout<<countWaysTopDown(n,k)<<endl;
	cout<<countWaysBottomUp(n,k)<<endl;
	cout<<countWaysOpt(n,k)<<endl;
	
	return 0;
}