#include<bits/stdc++.h>
using namespace std;


bool cmp(pair<int, int>& job1, pair<int, int>&job2)
{

	return (job1.first > job2.first);

}

void JSWD(vector<pair<int, int>>&job, int n) {

	sort(job.begin(), job.end(), cmp);
	// sort(job.begin(), job.end(), greater<pair<int,int>>());
	/*for (int i = 0; i < n; i++) {
		cout << job[i].first << " " << job[i].second << endl;
	}*/

	vector<int>slot(n + 1, -1);
	int profit = 0;

	for (int i = 0; i <n; i++) {

		int d = job[i].second;
		for (int j = d; j >= 1; j--) {
			if (slot[j] == -1) {
				slot[j] = i;
				profit += job[i].first;
				break;
			}
		}
	}

	cout<<profit<<endl;
	for(int i=1;i<=n;i++){
		cout<<slot[i]<<" ";
	}

}


int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	vector<pair<int, int>>job(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> job[i].first >> job[i].second;


	}

	JSWD(job, n);


	/*for(int i=1;i<=n;i++){
		cout<<job[i].first<<" "<<job[i].second<<endl;
	}*/






}


/*

4
100 2
10 1
15 2
27 1

*/