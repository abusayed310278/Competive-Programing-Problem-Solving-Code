#include<bits/stdc++.h>
using namespace std;

string s1="abcd",s2="abedg";
int ans=0;

//Top Down Approach: Tc:
int lcs(int i,int j,vector<vector<int>>& dp)
{
	if(i==s1.length()  || j== s2.length())return 0;

	if(dp[i][j]!=-1)return dp[i][j];


	if(s1[i]==s2[j] && i<s1.length() && j<s2.length())
		ans= 1+lcs(i+1,j+1,dp);
	else{
		ans= max(lcs(i+1,j,dp),lcs(i,j+1,dp));
	}

	return dp[i][j]=ans;

}

//Bottom Up: Tc:

int lcs()
{
	int n1=s1.length();
	int n2=s2.length();

	vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	//print
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[n1][n2];
}

int SubsequenceCount(int i,int j,vector<vector<int>>& dp)
{
	if(i==s1.length()  || j== s2.length())return 0;

	if(dp[i][j]!=-1)return dp[i][j];


	if(s1[i]!=s2[j] && i>=0 && j>=0)
		ans= SubsequenceCount(i-1,j,dp);
	else{
		ans= SubsequenceCount(i-1,j-1,dp)+SubsequenceCount(i-1,j,dp);
	}

	return dp[i][j]=ans;

}



int main()
{
	int n1=s1.length();
	int n2=s2.length();

	vector<vector<int>>dp(n1,vector<int>(n2,-1));

	//cout<<lcs(0,0,dp)<<endl;
	//cout<<lcs()<<endl;
	cout<<SubsequenceCount(n1-1,n2-1,dp)<<endl;
	return 0;
}