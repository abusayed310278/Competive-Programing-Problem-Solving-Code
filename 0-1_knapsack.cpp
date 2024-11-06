#include<bits/stdc++.h>
using namespace std;


int Max(vector<bool>& x,vector<float>& pbw,int n)
{
	int index=1;
	float maxi=0;
	for(int i=0;i<n;i++)
	{	
		if(maxi< pbw[i] && x[i]==0)
		index=i;
		pbw[i]=0;
	}
	return index;
}

int knpsk(int m,vector<int>& p,vector<int>& w,vector<float>&pbw,vector<bool>& x,int n)
{
	int profit=0;
	int index=Max(x,pbw,n);
	
	while(m>0){	
	
		if(m-w[index]>=0){
			profit+=w[index];	
			m-=w[index];
			x[index]=1;
		}else{
			profit+=w[index]*(m/w[index]);
			m=0;
			x[index]=m/w[index];
			
		}	
	}
	cout<<profit<<endl;
	
}
int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	int n;cin>>n;
	vector<int>p(n+1);
	vector<int>w(n+1);
	for(int i=0;i<n;i++){ int x;cin>>x; p[i]=x; }
	for(int i=0;i<n;i++){ int x;cin>>x; w[i]=x; }

	vector<float>pbw(n+1,false);	
	for(int i=0;i<n;i++){ pbw[i]=(float)p[i]/w[i]; }
	
	vector<bool>x(n+1,false);

	int m=15;
	
	knpsk(m,p,w,pbw,x,n);
	return 0;	
}


/*

10 5 15 7 6 18 3
2 3 5 7 1 4 1

*/