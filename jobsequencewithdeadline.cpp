#include<bits/stdc++.h>
using namespace std;


// int cmp(struct job a, struct job b)
// {

// 	return a.p > b.p;
// }

/*void JSWD(vector<job>& arr, int n) {

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

}*/


int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	vector<pair<int,int>>job;
	for (int i = 0; i < n; i++) {
		int p, d,jobno; cin >> p >> d;
		job.push_back({p,d});	

	}

	
	
	// for(auto x:job){
	// 	cout<<x.first<<" "<<x.second<<endl;
	// }

	
	

}


/*

4
100 2 
10 1
15 2
27 1

*/