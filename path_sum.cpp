#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define l long
#define F  first
#define S  second
#define pb  push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;
vector<vector<int>>g;
vector<int>parent,depth,heavy,size;
vector<int>head,lt,pos,fn,value;

int idx;

void dfs(int u){

    for(int c:g[u]){

        depth[c]=depth[u]+1;
        parent[c]=u;
        dfs(c);

        size[u]+=size[c];
        if(size[c] >size[ heavy[u] ]){
            heavy[u]=c;
        }

    }

    size[u]++;

}

void hld(int u,int chain){

    head[u]=chain;
    lt[idx]=value[u];
    pos[u]=idx;idx++;

    if(heavy[u]!=0){
        hld(heavy[u],chain);
    }

    for(int c:g[u]){
        if(heavy[u]!=c){
            hld(c,c);
        }
    }

}



void add(int i,int val){

    while(i<fn.size()){

        fn[i]+=val;
        i+=(i&(-i));
    }


}

int query(int i){

    int sum=0;
    while(i>0){
        sum+=fn[i];
        i-=i&(-i);
    }
    return sum;
}

void build(){

    for(int i=1;i<=fn.size();i++){
        add((i,lt[i]));
    }

}


int lca(int a,int b){

    int sum=0;
    while(head[a]!=head[b]){

        //we assume a is greater than b so we swap them
        if(depth[head[a]] < depth[head[b]])swap(a,b);

        sum+=query(pos[a])-query(pos[head[a]]-1);
        a=parent[head[a]];

    }


    if(depth[a] < depth[b])swap(a,b);

    sum+=query(pos[a])-query(pos[b]-1);

    return sum;
}


void solve() {
    
    int n;cin>>n;
    value.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>value[i];
    }


    g.resize(n+1);
    
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        g[x].push_back(i);
    }

    parent.resize(n+1); depth.resize(n+1); size.resize(n+1); heavy.resize(n+1);

    dfs(1);
    head.resize(n+1); lt.resize(n+1); pos.resize(n+1);
    idx=1;

    hld(1,1);
    fn.resize(n+1);
    build();

    int q; cin>>q;
    while(q--){

        int t;cin>>t;
        if(t==1){
            int i; cin>>i; int val; cin>>val;
            int delta=-lt[pos[i]]+val;
            add(pos[i],delta);
            lt[pos[i]]=val;


        }else{
            int a,b; cin>>a>>b;
            cout<<lca(a,b)<<endl;
        }

    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*

1
8
4 7 9 5 2 1 3 5
1 1 1 4 3 4 1
7
2 2 6
1 6 2
2 2 6
2 5 7
1 3 12
2 6 8
2 7 6




*/