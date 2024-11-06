#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define lli long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const ll mod = 1e9 + 7;

void solve()
{
    // Write your solution code here
    int n;
    cin >> n;
    cout << "1 ";
    for (int i = 0; i < n; i++)
        cout << (1LL << i) << " ";

    cout << "\n";
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