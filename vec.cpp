#include<bits/stdc++.h>
using namespace std;
#define inf 1e5+10

void func(string s){

	int ind=0;

	for(int i=0; i<s.length(); i++){

		if(s[i]==' '){ s[i+1]=toupper(s[i+1]) ; continue;}
		else s[ind++]=s[i];


	}

	cout<<s.substr(0,ind);
}



int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s="";
	// string s="I got intern at geeksforgeeks";
	// char s[100];
	getline(cin,s);
	cout<<s;
	// func(s);
	return 0;
}



/*

6 7
0 1 5
1 2 -2
1 5 -3
2 4 3
3 2 6
3 4 -2
5 3 1



*/