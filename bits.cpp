#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>nums{1,2,2};
	vector<vector<int>>res;
	vector<int>v1;

	int n=nums.size();

	

	for(int i=0;i <(1<<n);i++)
	{
		for(int j=0;j <n ;j++)
		{
			
			if( (i>>j) &1)
			{

				v1.push_back(nums[j]);

				//cout<<nums[j];

			}
		}
		auto it=find(res.begin(),res.end(),v1);

		if(it!=res.end()){
			res.push_back(v1);
			//cout<<endl;

		}

	}

	for(int i=0;i< res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}