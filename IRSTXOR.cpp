#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
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

    int c;
    cin >> c;
    int id = 0;

    for (int i = 31; i >= 0; i--)
    {
        if ((1 << i) & c)
        {
            id = i;
            break;
        }
    }

    int a=0, b=0;
    int flag = 1;
    for (int i = id; i >= 0; i--)
    {
        if ((1 << i) & c)
        {
            if (flag)
            {
                a |= (1 << i);
                flag = 0;
            }
            else
            {
                b |= (1 << i);
                // flag=1;
                
            }
        }
        else
        {
            a |= (1 << i);
            b |= (1 << i);
        }
    }

    cout << a * b << endl;
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