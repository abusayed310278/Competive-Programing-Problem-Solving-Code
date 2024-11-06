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
vector<int> fn;

// build and update
void add(int i, int x)
{

    while (i<fn.size())
    {
        fn[i] += x;
        x += x & (-x);
    }
}

int getsum(int x){

    int sum=0;
    while(x){
        sum+=fn[x];
        x-=x&(-x);
    }

    return sum;

}



void solve()
{
    
    fn.resize(n + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}