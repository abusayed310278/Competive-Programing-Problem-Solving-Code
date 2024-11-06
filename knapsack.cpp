#include<bits/stdc++.h>
#define n 8
using namespace std;

int m=15;
int x[n]={0};
int p[n+1]={0,10,5,15,7,6,18,3};
int w[n+1]={0,2,3,5,7,1,4,1};
float pbw[n+1]={0};

int maxx()
{
	int index=1;
	float maxxx=0;
	for(int i=1;i<=n;i++)
	{	
		if(maxxx< pbw[i] && x[i]==0)
		index=i;
		pbw[i]=0;
	}
	return index;
}

int knpsk()
{
	int profit=0;
	int index=maxx();
	
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
	cout<<"profit:"<<profit;
	
}
int main()
{
	for(int i=1;i<=n;i++)
		pbw[i]=(float)p[i]/w[i];
	
	knpsk();
	return 0;	
}