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
const int MAX = 17; // for n is 10^5
vector<int> p;
vector<vector<int>> table;

int n;
void build()
{

    for (int i = 0; i < n; i++)
    {
        table[0][i] = p[i];
    }

    //table[0]=p;

    for(int i=1;i<MAX;i++){
        for(int j=0;j<n;j++){
            table[i][j]= table[i-1] [ table[i-1][j]   ];
        }
    }



}


int query(int u,int k){

    
    for(int i=0;i<MAX;i++){

        if(k&(1<<i)){
            u=table[i][u];
        }
    }

    return u;
}

void solve()
{
    cin >> n;

    p.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    table.resize(MAX, vector<int>(n));
    build();

    int q;cin>>q;
    while(q--){

        int node,k;cin>>node>>k;
        cout<<query(node,k)<<endl;

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