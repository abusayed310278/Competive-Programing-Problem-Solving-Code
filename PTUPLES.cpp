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
vector<int> prime(N);

void sieve()
{

    vector<int> isprime(N, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i < N; i++)
    {

        if (isprime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                isprime[j] = 0;
            }
        }
    }

    prime[0] = prime[1] = 0;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i] and isprime[i - 2])
        {
            prime[i] = 1 + prime[i - 1];
        }
        else
        {
            prime[i] = prime[i - 1];
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << prime[n] << endl;
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