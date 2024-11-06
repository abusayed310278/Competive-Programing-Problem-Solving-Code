#include<bits/stdc++.h>
using namespace std;

struct job {
	int jobno;
	int p, d;

	job(int _p, int _d, int _jobno) {
		p = _p; d = _d; jobno = _jobno;
	}
};

// int cmp(struct job a, struct job b)
// {

// 	return a.p > b.p;
// }

void JSWD(vector<job>& arr, int n) {

	// sort(arr, sizeof(n), cmp);
	vector<int>slot(n + 1, -1);
	int profit = 0;

	for (int i = 0; i < n; i++) {

		int d = arr[i].d;
		for (int j = d; j >= 1; j--) {
			if (slot[j] == -1) {
				slot[j] = i;
				profit += arr[i].p;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (slot[i])cout << slot[i] << " ";
	}

}


int main()
{

	freopen("inputf.in", "r", stdin);
	// freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int p, d; cin >> p >> d;
		vector<job>arr;
		// arr[i].p=p;
		// arr[i].d=d;
		// arr[i].jobno=i;
		// job ob(arr[i].p, arr[i].d, arr[i].jobno);
		job ob(p, d, i);

	}

}


/*

4
100 2 
10 1
15 2
27 1

*/