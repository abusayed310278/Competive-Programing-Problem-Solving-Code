#include<bits/stdc++.h>
using namespace std;
/*
MMI=modular multiplicative inverse question:

There are n children and k toffees.k<n count the number of ways to distribute toffee
among n students such that each students get 1 toffee only nCk.

n< 10^6 , k<n<10^6

solution:

n!/(r!* !(n*r))

*/
const int M=1e9+7;
const int N=1e6+10;
int fact[N];

int binaryExp(int a,long long b,int m){

    int ans=1;
    while(b>0) //while(b){}
    {
        if(b&1){
            ans=(ans*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b>>=1;
    }   

    return ans;
}

int main()
{
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);

    fact[0]=1;
    for(int i=2;i<N;i++){
        fact[i]=(fact[i-1]*1LL*i)%M;
    }

    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        int ans=fact[n];
        int denominator=(fact[n-r]*1LL*fact[r])%M;
        ans=ans*binaryExp(denominator,M-2,M);
        cout<<ans<<endl;
    }


    int a; 
    cin>>a;

    cout<<binaryExp(a,M-2,M)<<endl;

    

    return 0;
}

/*

50^64^32

*/