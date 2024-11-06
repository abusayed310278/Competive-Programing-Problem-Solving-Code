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
vector<int> isPrime(N, 1);
void pre()
{

    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

void solve()
{
    // Write your solution code here
    int h;
    cin >> h;
    int p = 1;
    int ans = 0;
    bool flag = false;
    while (p <= h)
    {
        if (isPrime[h])
        {
            h -= h;
        }
        h -= p;
        p *= 2;
        ans++;
        if (h == 0)
        {
            flag = true;
            break;
        }
    }

    // cout << (flag ? ans : -1) << endl;
    cout << ans << endl;
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