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

void solve()
{
    // Write your solution code here
    long long n, k;
    cin >> n >> k;
    string ans = "";
    vector<long long> arr(26);
    for (int i = 0; i < 26; i++)
    {
        arr[i] = pow(2, i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 25; j >= 0; j--)
        {
            if (k >= arr[j] + n - i)
            {
                ans += ('a' + j);
                k -= arr[j];
                break;
            }
        }
    }
    if (ans.size() == n && k == 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
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