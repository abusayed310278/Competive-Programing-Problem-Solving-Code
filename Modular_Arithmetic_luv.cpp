#include<bits/stdc++.h>
using namespace std;

/*
Given a number N.print its factorial.
Constraints:
1<=N<=100

print answer module M where M=47


*/

long long int factCal(int n){

	long long int fact=1;
	int M=47;

	for(int i=2;i<=n;i++){
		fact=(fact*i)%M;
	}

	cout<<fact<<endl;
}

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	int t;cin>>t;

	while(t--){

		int n;cin>>n;
		factCal(n);

	}
	

	return 0;
}

/*

4
3 19 20 21 


*/