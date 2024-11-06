#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int dp[N];

//Top down apporach: Tc=
int minArrayJumpTopDown(int n,vector<int>& arr,int i)
{
	if(i==n-1)return 0;
	if(i>=n)return INT_MAX;

	if(dp[i]!=-1)return dp[i];

	int steps=INT_MAX;
	int max_jump=arr[i];

	for(int jump=1;jump<max_jump;jump++)
	{
		int subprob=minArrayJumpTopDown(n,arr,i+jump);
		if(subprob!=INT_MAX){
			steps=min(steps,subprob+1);
		}
	}
	
	return dp[i]=steps;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	memset(dp,-1,sizeof(dp));
	vector<int>arr{3 ,4 ,2 ,1 ,2 ,3 ,7 ,1 ,1 ,3};
	/*int n;cin>>n;
	while(n--){
		int x;cin>>x;
		arr.push_back(x);
	}*/
	int n=arr.size();
	cout<<n<<endl;

	// cout<<minArrayJumpTopDown(n,arr,0)<<endl;
	
	
	return 0;
}