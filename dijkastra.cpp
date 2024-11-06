#include<bits/stdc++.h>
using namespace std;

int minCall(vector<int>& d,vector<int>& st,int n){

    int minCost=INT_MAX,min_index;
    for(int i=0;i<n;i++){
        if(st[i]==0 && d[i] <=minCost)
            minCost=d[i],min_index=i;
    }
    return min_index;
}

void dijkastraCall(vector<vector<int>>&edges,vector<int>&st,vector<int>&d,int minCost,int n,int src){

    d[src]=0;
    for(auto &edge:edges){
        int x=edge[0];
        int y=edge[1];
        int wt=edge[2];

        int u=minCall(d,st,n);
        st[u]=1;
        if(!st[y] && d[u]!=INT_MAX && wt+d[u] <d[y])
            d[y]=wt+d[u];
    }
    int cost=0;
    for(int i=0;i<d.size();i++){
        cost+=d[i];
    }
    cout<<cost;
}


int main()
{
    int n,m;
    freopen("inputf.in","r",stdin);
    // freopen("outputf.in","w",stdout);
    cin>>n>>m;

    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        vector<int>v1;
        cin>>u>>v>>wt;
        v1.push_back(u);
        v1.push_back(v);
        v1.push_back(wt);
        edges.push_back(v1);
        v1.clear();

    }
    vector<int>st(n+1,false);
    // memset(st,false,sizeof(st));

    vector<int>d(n+1,INT_MAX);
    // memset(d,INT_MAX,sizeof(d));
    int minCost=INT_MAX;

    dijkastraCall(edges,st,d,minCost,n,1);

    return 0;
}

/*

6 9
1 2 1
2 4 2
4 6 1
1 3 5
2 3 2
2 5 1
3 5 2 
5 6 2
4 5 3


*/