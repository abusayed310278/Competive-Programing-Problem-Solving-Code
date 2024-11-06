#include<bits/stdc++.h>
#define int long long int

using namespace std;

int memo[10][2][90];
string s;

int dp(int index,bool last,int sum)
{
	if(index==s.size()){
		return sum;
	}
	if(memo[index][last][sum]!=-1)return memo[index][last][sum];

	int till=(last ?s[index]-'0' :9);
	int ans=0;
	for(int i=0;i<=till;i++){
		ans+=dp(index+1,last &&(i==till) ,sum+i );
	}
	return memo[index][last][sum]=ans;
}

int solve(int n){
	s=to_string(n);
	return dp(0,true,0);
}

int32_t main()
{
	#ifndef st
		freopen("in.txt","r",stdin);
		freopen("pp.txt","w",stdout);
	#endif
	memset(memo,-1,sizeof(memo));

	while(1){
		int a,b;
		cin>>a>>b;
		if(a==-1 and b==-1)break;
		cout<<solve(b)-solve(a-1)<<endl;
	}
	return 0;
}