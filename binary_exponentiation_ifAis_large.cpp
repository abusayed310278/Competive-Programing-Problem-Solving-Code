#include<bits/stdc++.h>
using namespace std;
/*
Binary exponentiation for large a number 


*/

const long long int M=1e18+7;

//divide and conquer,Tc=log(b)

int binaryExpRec(int a,int b){

	if(b==0)return 1;

	int res=binaryExpRecur(a,b/2);  
	
	if(b&1){
		return (a*((res*1LL*res)%M))%M;	
	}else{
		return (res*1LL*res)%M;	
	}

	
}


//iterative method,Tc=log(b)
//if a<=1e18
int binaryExpIterIfAIsLarger(int a,int b){

	a%=M;
	// a=binaryExpRec(2,1024); //or 33 No line same 
	int ans=1;
	while(b>0) //while(b){}
	{
		if(b&1){
			ans=(ans*1LL*a)%M;
		}
		a=(a*1LL*a)%M;
		b>>=1;
	}	

	return ans;
}






int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	int a,b; // a=division ,b=dividend
	cin>>a>>b;
	
	//cout<<powr(a,b);

	//a^b
	cout<<binaryExpIterIfAIsLarger(a,b)<<endl;

	return 0;
}

/*

2 5


*/