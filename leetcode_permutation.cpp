#include<bits/stdc++.h>
using namespace std;

class Solution{

 public:

	vector<vector<int>> permuation(int nums[])
	{
		vector<vector<int>>result;
		int n=arrayLength(nums);
		permute(result,0,n-1,nums);
		return result;

	}
	void permute(vector<vector<int>>& result,int l,int r,vector<int>& nums)
	{
		if(l==r){
			result.push_back(toList(nums));
			
		}else{
			for(int i=l;i<=r;i++){
					
				swap(nums[l],nums[i]);
				permute(result,l+1,r,nums);

				swap(nums[l],nums[i]);
					
			}
		}
	}
	vector<int> toList(int nums[]){
		vector<int>res;
		for(int c:nums){
			res.push_back(c);
		}
		return res;
	}
	

};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int a;
	cin>>a;
	int arr[a];

	for(int i=0;i<a;i++){
		int x;
		cin>>x;
		arr[i]=x;
	}

	Solution ob;
	vector<vector<int>>result=ob.permuation(v);
	
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			cout<<arr[j];
		}
		cout<<endl;
	}	

	return 0;
}