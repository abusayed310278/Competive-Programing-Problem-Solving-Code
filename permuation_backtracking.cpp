//Given a string print all those permutation which do not contains "AB" as a substring.
#include<bits/stdc++.h>
using namespace std;

bool isSafe(string s,int l,int i,int r){
	if(l!=0 && s[l-1]=='a' && s[i]=='b')return false;
	if(r==l+1 && s[l]=='a' && s[l]=='b')return false;
	return true;
}

//Backtracking approach: O(n!*n) 
void permuation(string &s,int l,int r)
{
	if(l==r){
		if(s.find("ab")==string::npos)
		cout<<s<<endl;
		return;
	}else{
		for(int i=l;i<=r;i++){
			if(isSafe(s,l,i,r)){	
				swap(s[l],s[i]);
				permuation(s,l+1,r);
				swap(s[l],s[i]);
			}	
		}
	}

}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	permuation(s,0,n-1);

	return 0;
}