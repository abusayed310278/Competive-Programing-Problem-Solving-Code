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
    int N;
    cin >> N;

    int A[N];
    for (int &i : A)
        cin >> i;

    bool ok = A[0] == A[N - 1];

    for (int i = 1; i < N; ++i)
    {
        if (A[i] == A[N - 1] && A[i - 1] == A[0])
        {

            ok = 1;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
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