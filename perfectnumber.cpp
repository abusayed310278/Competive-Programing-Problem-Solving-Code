#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num)
    {
        if(num==1)return false;
        
        int sum=0;
        for(int i=1;i<num;i++)
        {
            if(num%i==0){
                sum+=i+num/i;
            }
        }
        return num==sum;
    }
};

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    Solution ob;
    cout<<ob.checkPerfectNumber(n)<<endl;
    return 0;
}