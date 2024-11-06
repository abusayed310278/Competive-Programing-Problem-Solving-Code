#include<bits/stdc++.h>
using namespace std;

#define bitsize 10

//Tc: Theta(n^2),theta(1)
void oddAppearing() {

	vector<int> arr {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};


	for (int i = 0; i < arr.size(); i++) {

		int count = 0;

		for (int j = 0; j < arr.size(); j++) {
			if (arr[i] == arr[j]) {
				count++;
			}
		}

		if (count % 2 != 0) {
			cout << arr[i] << " ";

		}

	}

}

//Tc: Theta(n)
void oddAppearingXor() {

	vector<int> arr {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
	int ans = 0, res1 = 0, res2 = 0;
	for (int i = 0; i < arr.size(); i++) {
		ans ^= arr[i];
	}
	// cout << ans << endl;
	int mask = ans & (~(ans - 1));//right most set bit

	for (int i = 0; i < arr.size(); i++) {
		if ((mask & arr[i]) != 0)
			res1 ^= arr[i];
		else
			res2 ^= arr[i];
	}
	cout << res1 << " " << res2 << endl;

}



int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	// oddAppearing();
	oddAppearingXor();


	return 0;
}