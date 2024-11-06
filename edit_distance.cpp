#include<bits/stdc++.h>
using namespace std;

int memo[2000][2000];
string a,b;

int dp(int i,int j)
{
	if(i==a.size() && j==b.size())return 0;
	if(i==a.size())return (b.size()-j);
	if(j==b.size())return (a.size()-i);

	if(memo[i][j]!=-1)return memo[i][j];

	int ans;
	if(a[i]!=b[j])
		ans=1+min({dp(i+1,j),dp(i+1,j+1)});
	else{
		ans=dp(i+1,j+1);
	}

	return memo[i][j]=ans;
}

int main()
{	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	memset(memo,-1,sizeof(memo));

	int t;cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<dp(0,0)<<endl;
	}

	return 0;
}