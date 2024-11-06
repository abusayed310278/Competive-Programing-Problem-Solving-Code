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
// https://www.hackerrank.com/challenges/poker-nim-1/problem?isFullScreen=false

void solve()
{

    int n, k;
    cin >> n >> k;
    int nim_xor = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nim_xor ^= x;
    }

    cout << (nim_xor ? "First" : "Second") << endl;
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