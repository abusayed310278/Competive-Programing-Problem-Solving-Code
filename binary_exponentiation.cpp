#include<bits/stdc++.h>
using namespace std;

/*
Binary exponentiation Recursive method

*/

const int M=1e9+7;


//Tc=O(n)
int powr(int a,int b){

	int ans=1;
	for(int i=0;i<b;i++){
		ans*=a;
		ans%=M;
	}
	return ans;
}

//divide and conquer,Tc=log(b)
int powrCal(int a,int b){

	if(b==0)return 1;
	
	if(b%2==0)
		return powrCal(a,b/2)*powrCal(a,b/2);	
	return a*powrCal(a,b/2)*powrCal(a,b/2);	

	
}

//divide and conquer,Tc=log(b)
int binaryExpRecur(int a,int b){

	if(b==0)return 1;

	long int res=binaryExpRecur(a,b/2);  
	
	if(b&1){
		return (a*((res*res)%M))%M;	
	}else{
		return (res*res)%M;	
	}

	
}

//divide and conquer,Tc=log(b)

int binaryExpRecurCal(int a,int b){

	if(b==0)return 1;

	int res=binaryExpRecur(a,b/2);  
	
	if(b&1){
		return (a*((res*1LL*res)%M))%M;	
	}else{
		return (res*1LL*res)%M;	
	}

	
}

//divide and conquer,Tc=log(b)
int binaryExpRecurCall(int a,int b){

	if(b==0)return 1;

	long long int res=binaryExpRecur(a,b/2);  
	
	if(b&1){
		return (a*((res*res)%M))%M;	
	}else{
		return (res*res)%M;	
	}

	
}



int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	int a,b; // a=division ,b=dividend
	cin>>a>>b;
	
	//cout<<powr(a,b);

	//a^b
	cout<<powrCal(a,b)<<endl;

	cout<<binaryExpRecur(a,b)<<endl;

	return 0;
}

/*

2 5


*/