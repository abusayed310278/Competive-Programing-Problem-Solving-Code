#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define lli long long
#define l long
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

const int mod = 1e9 + 7;

vector<int> allp;

void generate()
{

    for (int i = 0; i < 32768; i++)
    {
        string s = to_string(i);
        string t = s;
        reverse(begin(t), end(t));
        if (s == t)
            allp.push_back(i);
    }
}

void solve()
{
    // Write your solution code here
    int n;
    cin >> n;
    unordered_map<int, int> fre;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {

        cin >> v[i];
    }

    int ans = 0;
    for (auto ele : v)
    {
        fre[ele]++;
        for (auto x : allp)
        {
            ans += fre[ele ^ x];
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    generate();
    while (t--)
    {
        solve();
    }

    return 0;
}