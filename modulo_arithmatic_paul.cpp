#include<bits/stdc++.h>
using namespace std;

/* modulo arithmatic: add,sub,mul,MMI,div
*/

const int p=7,N=1e5;
int fact[N];

int addm(int a, int b) {
	return (a+b)%p;
}

int subm(int a, int b) {
	return ((a-b)%p+p)%p;
}

int mulm(int a, int b) { 
	return (a*1LL*b)%p;  //instead of 1LL we can use #define int long long int 
}

int multiply(int x,int y){
	int res=1;
	while(y){
		if(y&1){
			res=mulm(res,x);
			x=mulm(x,x);
			y/=2;

		}
	}
	return res;
}

int divm(int x,int y){
	return mulm(x,multiply(y,p-2));
}

void factorial(){
	
	fact[0]=fact[1]=1;

	for(int i=2;i<N;i++){
		fact[i]=mulm(fact[i-1],i);
	}
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	/*cout << addm(5, 3)<<endl;

	cout<<(-4%5)<<endl; //not correct

	cout<<subm(-3,5)<<endl;
	cout<<mulm(324,234)<<endl; */
	cout<<divm(50,2)<<endl; 
	cout<<divm(56,2)<<endl; 

	//factorial();

	//cout<<fact[5]<<endl;

	return 0;
}