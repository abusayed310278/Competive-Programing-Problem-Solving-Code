#include<bits/stdc++.h>
using namespace std;
const int n=4;
int x[n+1];


class Solution{
public:


    void show()
    {
        cout<<"path: ";
        for(int i=1;i<=n;i++)
            cout<<x[i]<<" ";
        cout<<endl;
    }

    bool isPlace(int q,int ith)
    {
        for(int col=1;col<q;col++)
            if(x[col]==ith || (q-ith)==(col-x[col]) || (q+ith)==(col+x[col]))
                return false;
        return true;
    }

    void NQueen(int q)
    {
        for(int ith=1;ith<=n;ith++)
        {
            if(isPlace(q,ith))
            {
                x[q]=ith;
                if(q==n)
                    show();
                else
                    NQueen(q+1);
            }
        }
    }
};

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    memset(x,false,sizeof(x));
    int q;
    cin>>q;
    Solution ob;
    ob.NQueen(q);
    return 0;
}

