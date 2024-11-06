#include <bits/stdc++.h>
using namespace std;

string stringWindow(string s, string p) {

	int FP[256] = {0};
	int FS[256] = {0};

	for (int i = 0; i < s.length(); i++) {
		FS[s[i]]++;
	}

	for (int i = 0; i < p.length(); i++) {
		FP[p[i]]++;
	}

	//sliding window algorithms

	int cnt = 0, start = 0, start_idx = -1, min_so_far = INT_MAX, window_size;

	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];
		FS[ch]++;

		if (FP[ch] != 0 and FS[ch] <= FP[ch]) {
			cnt++;
		}

		if (cnt == p.length()) {

			while (FP[start] == 0 or FS[s[start]] > FP[s[start]]) {
				FS[s[start]]--;
				start++;
			}

			window_size = i - start + 1;
			if (window_size < min_so_far) {
				min_so_far = window_size;
				start_idx = start;
			}
		}

	}

	if (start_idx == -1) {
		return "No window found";
	}

	return s.substr(start_idx, min_so_far);


}



// Driver Code
int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	string s, p; cin >> s >> p;

	cout << stringWindow(s, p);

	return 0;
}
/*

hello_world
lol

*/