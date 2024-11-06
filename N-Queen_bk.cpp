#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    int show(int x[],int n){
        int result=1;
        cout<<"op:";
        for(int i=1;i<=n;i++){
            cout<<x[i]<<" ";
        }
        ++result;
        cout<<endl;
        return result;

    }

    bool isPlace(int q,int ith,int x[])
    {
        for(int col=1;col<q;col++)
            if(x[col]==ith || (q-ith)==(col-x[col]) || (q+ith)==(col+x[col]))
                return false;
        return true;
    }

    int NQueen(int q,int x[],int result,int n)
    {
        for(int ith=1;ith<=n;ith++)
        {
            if(isPlace(q,ith,x))
            {
                x[q]=ith;
                if(q==n){
                    ++result;
                }
                else
                    NQueen(q+1,x,result,n);
            }
        }
        return result*=2;
    }
    int totalNQueens(int n) {
        int x[n+1];
        memset(x,0,sizeof(x));
        int result=1;
        
        if(n==1)
            return 1;
        else
            return NQueen(1,x,result,n);
    }


};

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    Solution ob;
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<ob.totalNQueens(n)<<endl;
    }
        
    return 0;
}

