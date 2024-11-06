#include<bits/stdc++.h>
using namespace std;


vector<int>nums1;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=m+n-1;
        int i=(m-1);
        int j=(n-1);
        while(j>=0){
            if(i>=0 && nums1[i] > nums2[j]){
                nums1[l--]=nums1[i--];
                
            }else{
                nums1[l--]=nums2[j--];
                
                
            }
        }
        
        
    }
};

int main()
{
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    vector<int>nums2;
    int m,n;cin>>m;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        nums1.push_back(x);
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        nums2.push_back(x);
    }
    Solution ob;
    ob.merge(nums1,m,nums2,n);

    for(int i=0;i<(m+n);i++)
            cout<<nums1[i]<<" ";

    return 0;
}