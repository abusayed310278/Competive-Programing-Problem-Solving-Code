#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int dp[N];

int rob(vector<int>& nums,int i){

	if(i<0)return 0;

	if(dp[i]!=-1)return dp[i];

	return dp[i]=max( rob(nums,i-1), rob(nums,i-2)+nums[i] );
}

int main()
{

	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);

	vector<int>nums{1,2,3,1};

	int i=nums.size();

	memset(dp,-1,sizeof(dp));

	cout<<rob(nums,i-1);


	return 0;
}