#include<bits/stdc++.h>
using namespace std;

string s;

int dp(int index,bool last,int sum)
{
	if(index==s.size()){
		return sum;
	}

	int till=(last ?s[index]-'0' :9);
	int ans=0;
	for(int i=0;i<=till;i++){
		ans+=dp(index+1,last &&(i==till) ,sum+i );
	}
	return ans;
}

int solve(int _n){
	s=to_string(_n);
	return dp(0,true,0);
}

int main()
{
	#ifndef st
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	while(1){
		int a,b;
		cin>>a>>b;
		cout<<solve(b-1)-solve(a-1)<<endl;
	}
	return 0;
}