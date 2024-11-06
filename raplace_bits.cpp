#include<bits/stdc++.h>
using namespace std;
/*
Replace bits in N by M
	you are given two 32-bit numbers,N and M and two bit positions i and j.
	write a method to set all bits between i and j in N equal to M.
	M(becomes a substring of N locationed at and starting at j)
	Example:
	N=10000000000
	M=10101
	i=2,j=6
	output: 1001010100
*/

int clearBitsInRange(int n, int i, int j) {
	int a = (-1 << (j + 1));
	int b = (1 << i) - 1;
	int mask = a | b;
	int ans = n & mask;

	return ans;
}

void replaceBits(int n, int i, int j, int m) {

	n=clearBitsInRange(n, i, j);

	int mask = (m << i);
	int ans = n | mask;

	cout << ans << endl;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	replaceBits(15, 1, 3, 2);

	return 0;
}