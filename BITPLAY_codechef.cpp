#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define int long long
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

    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 0; i < n-1; i += 2)
    {
        char res = s[i + 2];
        char a = s[i], b = s[i + 1];

        if (res == '1')
        {
            if (a == '0' and b == '0'){
                ans = 0;
            }else{
                ans = (ans * 2) % mod;
            }
        }
        else
        {
            if (a == '0' and b == '0'){
                ans = (ans * 3) % mod;
            }
                
                
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
    while (t--)
    {
        solve();
    }

    return 0;
}