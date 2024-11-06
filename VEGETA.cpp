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

const int N = 1e6 + 1;
vector<lli> prime;

void sieve()
{

    prime.resize(N,0);
    for (int i = 2; i <= N; i++)
    {
        if (prime[i] == 0)
        {
            prime[i]++;
            for (int j = 2 * i; j <=N; j += i)
            {
                prime[j]++;
            }
        }
    }
}

void solve()
{
    // Write your solution code here
    lli n, m;
    cin >> n >> m;
    
    lli ans = 0;
    for (int i = n; i < m; i++)
        ans += prime[i];

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}