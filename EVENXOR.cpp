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
vector<int> a(1000);
void pre()
{

    int i = 0, val = 0;
    while (i < 1000)
    {
        int bit = __builtin_popcount(val);
        if (bit % 2 == 0)
        {
            a[i] = val;
            i++;
        }
        val++;
    }
}

void solve()
{
    // Write your solution code here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}