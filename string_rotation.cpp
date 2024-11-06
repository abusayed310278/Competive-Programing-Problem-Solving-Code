#include<bits/stdc++.h>
using namespace std;

//Tc:theta(n)
bool stringRotation(string &s1,string &s2){

	if(s1.length()!=s2.length())return false;

	return ((s1+s2).find(s2)!=string::npos);
}

int main()
{

	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	
	string s1,s2;
	cin>>s1>>s2;
	cout<<stringRotation(s1,s2);	

	return 0;
}

/*

abcd
cdab

abaaa
baaaa

abab
abba

*/