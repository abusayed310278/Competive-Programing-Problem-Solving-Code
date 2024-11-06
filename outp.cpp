#include<bits/stdc++.h>
using namespace std;

#define bitsize 10

//for gcc compiler computation

int main()
{

	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	
	/*int x=5;

	int a=x++ + x++ + ++x + x++;

	cout<<a<<" "<<x<<endl;

	int y=5;
	int b=++y + y++ + y++ + ++y;
	cout<<b<<" "<<y<<endl;
	
	int aa=1;
	int bb=aa++ + aa++;

	cout<<bb<<" "<<aa<<endl;
*/
	int x=-1;

	cout<<bitset<bitsize>(x)<<endl;

	cout<<bitset<bitsize>(-1<<5)<<endl;

	return 0;
}