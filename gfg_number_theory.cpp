#include<bits/stdc++.h>
using namespace std;

int countDigit(int n){

	int cnt=0;
	while(n!=0){

		n/=10;
		++cnt;
	}
	return cnt;
}

int countDigitRec(int n){

	if(n==0)return 0;

	return 1+countDigitRec(n/10);
}

int countDigitLog(int n){

	return floor(log10(n))+1;
}

int main()
{
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);


	cout<<countDigit(135)<<endl;
	cout<<countDigitRec(135)<<endl;
	cout<<countDigitLog(135)<<endl;

	return 0;
}