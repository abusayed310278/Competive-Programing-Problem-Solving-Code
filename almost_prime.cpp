#include<bits/stdc++.h>
#define ll long long int
#define ld long double 
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

using namespace std;

const int N=3005;
vector<int>primes;

int seive(int n){
	int pr[n+1]={};
	for(int i=2;i<=n;i++){
		if(!pr[i]){
			primes.pb(i);
			for(int j=i;j<=n;j+=i){
				pr[j]++;
			}
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		if(pr[i]==2)ans++;
	}
	return ans;
}

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n;
	cout<<seive(n);
	return;
}

int32_t main()
{
	#ifndef bitset
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);	
	*/
	solve();

	return 0;
} 

