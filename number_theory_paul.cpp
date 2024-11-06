#include<bits/stdc++.h>
using namespace std;

/* modulo arithmatic: add,sub,mul,MMI,div
*/

const int p=7,N=10;
int fact[N];

//Tc: O(1)
int addm(int a, int b) {
	return (a+b)%p;
}

//Tc: O(1)
int subm(int a, int b) {
	return ((a-b)%p+p)%p;
}
//Tc: O(1)
int mulm(int a, int b) { 
	return (a*1LL*b)%p;  //instead of 1LL we can use #define int long long int 
}

//Tc: O(log(y))

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

//Tc: O(log(y))
int inv(int x){

	return multiply(x,p-2);
}

//Tc: O(log(y))
int divm(int x,int y){
	return mulm(x,multiply(y,p-2));
}

//Tc: O(N)
void factorial(){
	
	fact[0]=fact[1]=1;

	for(int i=2;i<N;i++){
		fact[i]=mulm(fact[i-1],i);
	}
}

//Tc: O(log(y))
int ncr(int n,int r){
	return mulm( mulm( fact[n],inv(fact[r]) ) ,inv(fact[n-r]) );
}
//Tc: O(log(y))
int npr(int n,int r){
	return mulm(fact[n]  ,inv(fact[n-r]) );
}

int main()
{
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	/*cout << addm(5, 3)<<endl;

	cout<<(-4%5)<<endl; //not correct

	cout<<subm(-3,5)<<endl;
	cout<<mulm(324,234)<<endl; */
	//cout<<divm(50,2)<<endl; 
	//cout<<divm(56,2)<<endl; 

	factorial();

	//cout<<fact[5]<<endl;

	cout<<ncr(5,2)<<endl;

	return 0;
}