#include <bits/stdc++.h>
using namespace std;

int min(int a,int b){
        return (a<b)?a:b;
}

int minSubArrayLen(int target, vector<int>& nums) {
        
       int n=nums.size(),i=0,j=0,k=0,ans=INT_MAX;
        long long sum=0;
        
        while(j<n){
            
            sum+=nums[j];
            if(sum < target)j++;
            
            if(target==sum){
                ++k;
                ans=(ans,k);
                i++;j++;
            }         
            
        }   
        return k;
}
    
    

 int main()
{

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};

    cout << minSubArrayLen(target,nums);

    return 0;
}   