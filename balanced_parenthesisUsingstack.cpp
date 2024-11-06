#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int>symbols{
 {'(',-1},
 {'{',-2},
 {'[',-3},
 {')',1},
 {'}',2},
 {']',3} 
};

string isBalanced(string &str){
	
	stack<char>st;
	for(char bracket:str){
		if(symbols[bracket]<0){
			st.push(bracket);
		}else{
			if(st.empty())return "No";
			char TOP=st.top();
			st.pop();
			if(symbols[TOP]+symbols[bracket]!=0)return "NO";
		}
	}	
	
	if(st.empty())return "Yes";
	return "No";

}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int t;cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<isBalanced(s)<<endl;
	}

	return 0;
}