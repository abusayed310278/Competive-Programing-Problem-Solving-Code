#include<bits/stdc++.h>
using namespace std;

#define bitsize 5

void leftshift(int n) {

	int x = (n << 1);

	cout << x << endl;
}

void rightshift(int n) {

	cout << (n >> 1) << endl;
}

void evenOdd(int n) {

	if (n & 1)
		cout << "odd" << endl;
	else
		cout << "even" << endl;

}

void count(int n) {

	int cnt = 0;

	while (n > 0) {

		if (n & 1) {

			++cnt;
		}
		n >>= 1;
	}
	cout << cnt << endl;
}

void countBitsHack(int n) {
	int ans = 0;
	while (n > 0) {
		n = n & (n - 1);
		ans++;
	}
	cout<<ans<<endl;
}


void getIthBit(int n, int ith) {

	int ans = n & (1 << ith) > 0 ? 1 : 0;

	cout << ans << endl;

}

void setIthBit(int n, int ith) {

	int ans = n | (1 << ith);

	cout << bitset<bitsize>(ans) << endl;

}


void updateIthBit(int n, int ith, int value) {
	int ans;

	//set to reset
	if (value == 1) {
		ans = n & (~(1 << ith));
	}

	//reset to set
	if (value == 0) {
		ans = n | (1 << ith);
	}

	cout << bitset<bitsize>(ans) << endl;

}

void clearIthBit(int n, int ith) {

	int ans = n & ( ~(1 << ith));

	cout << bitset<bitsize>(ans) << endl;

}

//preetk narang code
/*void updateithbit(int n,int i,int v){

	clearithbit(n,i);
	int mask = (v<<i);

	n |=mask;

	cout<<bitset<bitsize>(n)<<endl;
}*/

void clearLastBit(int n, int ith) {

	int ans = n & ( (-1 << ith));

	cout << bitset<bitsize>(ans) << endl;


}

void clearBitsInRange(int n, int i, int j) {
	int a = (-1 << (j + 1));
	int b = (1 << i) - 1;
	int mask = a | b;
	int ans = n & mask;

	cout << bitset<bitsize>(ans) << endl;


}

//ctrl+alt+f

void decimal_to_binary(int n) {

	int ans = 0, power = 1;

	while (n > 0) {
		int last_bit = (n & 1);
		ans += last_bit  * power;
		power *= 10;
		n = n >> 1;
	}

	cout << bitset<bitsize>(ans) << endl;
}

void powerOfTwo(int n) {

	int ans = n & (n - 1);
	// cout << ans << endl;

	if (ans == 0)
		cout << n << " is power of 2" << endl;
	else
		cout << n << " is not power of 2" << endl;
}



int main()
{

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n; cin >> n;

	/*leftshift(n);
	rightshift(n);
	evenOdd(n);*/
	// count(n);

	// getIthBit(n,3);
	// setIthBit(n,2);
	// clearIthBit(n,1);

	// updateIthBit(n,1,1);

	// updateithbit(n,1,1);

	// clearLastBit(757,5);

	// clearBitsInRange(31, 1, 3);

	// decimal_to_binary(9);

	// powerOfTwo(16);
	// powerOfTwo(15);
	// countBitsHack(9);

	return 0;
}