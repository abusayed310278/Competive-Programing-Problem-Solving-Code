#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int getX(string s){ return s[0]-'a';}
int getY(string s){ return s[1]-'0';}

void bfs(string src,string dest){
	
	int srcX=getX(src);
	int srcY=getX(src);
	int destX=getX(dest);
	int destY=getY(dest);

	
}

int main(){


	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	int t;cin>>t;

	vector<int>g[N];
	while(t--){
		cint>>s1>>s2;
		bfs(s1,s2);
	}

	
	return 0;
}

/*

5 5
1 4
2 3
2 5
2 4
3 5

*/