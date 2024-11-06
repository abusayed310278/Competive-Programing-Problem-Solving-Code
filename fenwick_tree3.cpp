#include<bits/stdc++.h>
using namespace std;

int a[100000];
int bit[100000]={0};


//range max query
int update(int i,int val,int n){

	while(i<=n){
		bit[i]=max(bit[i],val);
		i+=(i&(-i));
	}
}

int query(int i){
	int ans=0;
	while(i>0){
		ans=max(ans,bit[i]);
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

	// update(3,10,n);
	//query
	int q;cin>>q;
	while(q--){
		int idx;cin>>idx;
		cout<<query(idx)<<endl;
	}

	return 0;
}

/*

5
5 4 1 7 3
3
3
4
5



*/