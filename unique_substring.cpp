#include<bits/stdc++.h>
using namespace std;

string unique_substring(string str){
	int i=0,j=0,window_len=0,max_window_len=0,start_window=-1;

	unordered_map<char,int>m;

	while(j<str.length()){
		char ch=str[j];
		//if it is inside hashmap and its idx >= start of the current window
		if(m.count(ch) and m[ch]>=i){
			i=m[ch]+1;
			window_len=j-i; //updated remaining window len excluding current char
		}
		//update the last occurance
		m[ch]=j;
		window_len++;
		j++;

		//update max_window_len at every step
		if(window_len >max_window_len){
			max_window_len=window_len;
			start_window=i;
		}
		
	}
	return str.substr(start_window,max_window_len);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	string input;
	cin>>input;
	cout<<unique_substring(input);
	return 0;
}