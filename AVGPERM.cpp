#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n == 3)
    {
        cout << "1 2 3" << endl;
        return;
    }

    cout << n << " " << n - 2 << " ";
    for (int i = 1; i <= n - 4; i++)
        cout << i << " ";

    cout << n - 3 << " " << n - 1 << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}