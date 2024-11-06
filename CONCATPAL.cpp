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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    if (n > m)
        swap(n, m), swap(a, b);

    vector<int> cnta(26, 0), cntb(26, 0);
    for (auto x : a)
    {
        cnta[x - 'a']++;
    }

    for (auto x : b)
    {
        cntb[x - 'a']++;
    }

    bool flag = true;
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {

        if (cnta[i] > cntb[i])
            flag = false;

        odd += (cntb[i] - cnta[i]) % 2;
    }

    if (odd <= 1 and flag)
        cout << "YES\n";
    else
        cout << "NO\n";
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