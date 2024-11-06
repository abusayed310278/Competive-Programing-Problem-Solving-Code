#include<bits/stdc++.h>
using namespace std;
const int N=9;
int grid[N][N];

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
    }
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	vector<vector<char>>board;

	for(int i=0;i<N;i++){
		vector<char>temp;
		for(int j=0;j<N;j++){
			char x;
			cin>>x;
			temp.push_back(x);
		}
		board.push_back(temp);
		temp.clear();
	}

	

	/*for(auto &v:board){
		for(auto &x:v){
			cout<<x<<" ";
		}
		cout<<endl;
	}*/



	return 0;
}