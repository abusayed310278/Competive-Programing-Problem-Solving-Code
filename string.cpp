#include<bits/stdc++.h>
using namespace std;

string s;

void fun(string ans,int index,bool last)
{
	if(index==s.size()){
		cout<<ans<<endl;
		return;
	}
	int till=(last ?s[index]-'0' :9);
	
	for(int i=0;i<=till;i++){
		fun(ans+to_string(i),index+1,(last &&(i==till) ) );
	}
}

int main()
{
	#ifndef st
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin>>s;
	fun("",0,true);

	return 0;
}