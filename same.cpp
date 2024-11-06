#include<bits/stdc++.h>

using namespace std;

void revv(string s,int i){

	cout<<s[i];
	if(i==0)return;
	revv(s,i-1);
	// cout<<s[ind];
}

int main()
{

	string s="kamal";
	int n=s.length()-1;
	revv(s,n);

	return 0;
}