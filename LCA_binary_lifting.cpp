#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;
int n;
vector<vector<int>> g;
vector<int>level,parent;

void dfs(int u,int lv){

    level[u]=lv;
    for(auto child:g[u]){

        parent[child]=u;
        dfs(child,lv+1);

    }


}

vector<vector<int>>table;
const int maxbit=9;
void build(){

    // for(int i=0;i<=n;i++){

    //     table[0][i]=parent[i];

    // }

    table[0]=parent;

    for(int i=1;i<=maxbit;i++){
        for(int j=2;j<=n;j++){
            table[i][j]=table[i-1][ table[i-1][j] ];
        }
    }


}

int lca(int u,int v){

    if(level[u]>level[v])swap(u,v);

    //we assume level of v is greater than u
    int k=level[v]-level[u];
    for(int i=maxbit;i>=0;i--){
        if(k&(1<<i)){
            v=table[i][v];
        }
    }

    if(u==v)return u;

    for(int i=maxbit;i>=0;i--){
        int up=table[i][u]; int vp=table[i][v];
        if(up!=vp){
            u=up;v=vp;
        }
    }

    u=parent[u];

    return u;
}

void solve()
{

    cin >> n;
    g.resize(n + 1);
    level.resize(n+1);
    parent.resize(n+1);

    for (int i = 1; i <= n; i++)
    {

        
        int sz;
        cin >> sz;
        for (int j = 1; j <=sz; j++)
        {
            
            int x;
            cin >> x;
           g[i].push_back(x);
        }
    }

       
       dfs(1,1);
       table.resize(maxbit+1,vector<int>(n+1));
       build();

       int q;cin>>q;
       while(q--){

            int u,v;cin>>u>>v;
            cout<<lca(u,v)<<endl;

       } 
        
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}