#include<bits/stdc++.h>
using namespace std;

int a[100000];
int bit[100000]={0};


//range sum query
int update(int i,int inc,int n){

	while(i<=n){
		bit[i]+=inc;
		i+=(i&(-i));
	}
}

int query(int i){
	int ans=0;
	while(i>0){
		ans+=bit[i];
		i-=(i&(-i));
	}
	return ans;
}

int main(){

	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	//build BIT
	int n;cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		update(i,a[i],n);
	}

	//query
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		cout<<query(r)-query(l-1)<<endl;
	}

	return 0;
}

/*

5
2 3 1 4 7
3
1 2
2 4
5 5


*/