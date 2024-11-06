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
    int k;
    cin >> k;
    int s = (k + 1) / 2;

    int mat[k][k]={0};
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int val = (s + j) % k;
            if (val == 0)
                val = k;
            mat[i][j] = val;
        }
        s -= 1;
        if (s == 0)
            s = k;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    // cout<<"\n";
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