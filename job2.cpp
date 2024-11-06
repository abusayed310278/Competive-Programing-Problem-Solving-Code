#include<bits/stdc++.h>
using namespace std;


// /*/*bool cmp(vector<int>& job1, vector<int>&job2)
// {

// 	return (job1[0] > job2[0]);

// }

// void JSWD(vector<vector<int>>& job, int n) {

// 	sort(job.begin(), job.end(),cmp );
// 	/*for(int i=0;i<job.size();i++){
// 		for(auto x:job[i]){

// 			cout<<x<<" ";
// 		}cout<<endl;
// 	}
// */
// 	vector<int>slot(n + 1, -1);
// 	int profit = 0;

// 	for (int i = 0; i <n; i++) {

// 		int d = job[i][1];
// 		for (int j = d; j >= 1; j--) {
// 			if (slot[j] == -1) {
// 				slot[j] = job[i][2];
// 				profit += job[i][0];
// 				break;
// 			}
// 		}
// 	}

// 	cout<<profit<<endl;
// 	for(int i=1;i<=n;i++){
// 		cout<<slot[i]<<" ";
// 	}

// }*/*/




int main()
{

	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);

	int n; cin >> n;
	vector<vector<int>>job[n + 1];
	for (int i = 0; i < n; i++) {
		int p, d, jobno; cin >> p >> d >> jobno;
		job[i].push_back({p, d, jobno});

	}

	// JSWD(job, n);



}


/*

4
100 2
10 1
15 2
27 1

*/