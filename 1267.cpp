#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);


	vector<vector<int>>a;

	int n;cin>>n;
	// int k=n;
	while(n--){
		vector<int>v;
		for(int i=1; i<=2; i++){
			int x;cin>>x;
			v.push_back(x);
		}
		a.push_back(v);
		v.clear();
	}

	for(int i=0; i<5; i++){

		int x=a[i][0];
		int y=a[i][1];

		cout<<"["<<x<<","<<y<<"]"<<endl;
	}

	return 0;
}