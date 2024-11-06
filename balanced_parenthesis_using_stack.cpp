#include<bits/stdc++.h>
using namespace std;

string balancedParenthesis(string &str){
	int i=0;
	int n=str.length();
	stack<char>p;

	while(i<n){
		if(str[i]=='(' || str[i]=='{' || str[i]=='['){
			p.push(str[i]);
			i++;
		}
		else if(str[i]==')' || str[i]=='}' || str[i]==']'   ){
			p.pop();
			i++;
		}

		
	}
	if(!p.empty())
			return "No";
		else
			return "Yes";

}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int t;cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<balancedParenthesis(s)<<endl;
	}

	return 0;
}