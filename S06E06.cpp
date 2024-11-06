#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long int
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
    int n, k;
    cin >> n >> k;
    multiset<int> q;
    while (n > 0)
    {

        q.insert(n % 10);
        n /= 10;
    }

    while (k--)
    {
        int ele = *(begin(q));

        if (ele == 9)
            break;
        q.erase(begin(q));
        ele = ele + 1;
        q.insert(ele);

        // ans=(ans*ele)%mod;
    }

    int ans = 1;
    for (auto it : q)
        ans *= it;

    cout << ans << endl;
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