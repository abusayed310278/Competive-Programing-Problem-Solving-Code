//Given a string print all those permutation which do not contains "AB" as a substring.
#include<bits/stdc++.h>
using namespace std;

//Naive approach 
void permuation(string s,int l,int r)
{
	if(l==r){
		//if(s.find("ab")==string::npos)
		cout<<s<<endl;
		return;
	}else{
		for(int i=l;i<=r;i++){
			swap(s[l],s[i]);
			permuation(s,l+1,r);
			swap(s[l],s[i]);
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