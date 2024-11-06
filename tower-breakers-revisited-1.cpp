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
int prsum[N];

void seive()
{

    vector<int> pr(N, 1);
    for (int i = 2; i < N; i++)
    {

        if (pr[i])
        {
            prsum[i] = 1;
            for (int j = 2 * i; j < N; j += i)
            {
                int jj = j;
                while (jj % i == 0)
                {
                    jj /= i;
                    prsum[j]++;
                }
                pr[j] = 0;
            }
        }
    }
}

void solve()
{

    int n;
    cin >> n;
    int xs = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        xs ^= prsum[x];
    }

    cout << (xs ? 1 : 2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    seive();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}