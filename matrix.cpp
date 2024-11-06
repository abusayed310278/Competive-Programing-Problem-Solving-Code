#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {

	vector<vector<int>>ans;

	int r = matrix.size() - 1;
	int c = matrix[0].size() - 1;

	for (int i = 0; i <= r; i++) {
		vector<int>v1;
		for (int j = r; j >= 0; j--) {
			v1.push_back(matrix[j][i]);
		}
		ans.push_back(v1);
		v1.clear();
	}

	for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main()
{

	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	
	/*vector<vector<int>> matrix = {
		{5,1,9,11},
		{2,4,8,10},
		{13,3,6,7},
		{15,14,12,16}
	};*/

	vector<vector<int>>matrix = {{1,2,3},{4,5,6},{7,8,9}};

	rotate(matrix);
	return 0;
}