#include<bits/stdc++.h>
using namespace std;

int sod(int t){

    int sum=0;
    while(t!=0){
        sum+=t%10;
        t/=10;
    }

    return sum;
}

int smithNum(int n) {
    
    
	int s=0,t=n;
	while(n%2==0){
		s+=2;
		n/=2;
	}
    
    for(int i=3; i<=t/2; i+=2){
        
        while(n%i==0){
            s+=sod(i);
            n/=i;
        }
        
    }
    return (n>2 or s!=sod(t)) ?0 :1;
    
}


int smithNumber(int n){


	int i=2,s=0,t=n;
	while(n>1){

		if(n%i==0){
			s+=sod(i);
			n/=i;
		}else i++;
	}

	return s==sod(t);
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n;cin>>n;

	cout<<smithNum(n);
	// smithNum(n);
	// cout<<smithNumber(n);

	return 0;
}


